#include <vector>
#include <iostream>
#include <iomanip>
#include "Product.cpp"

#define MAX_FILLED 0.75
#define C 1
#define D 1

using namespace std;

/**
 * Класс хэш-таблицы
 */
class HashTable {
private:
    int size = 10; // размер таблицы
    int filled; // кол-во заполненных ячеек
    int removed; // кол-во удаленных ячеек
    vector<Product*> products; // массив товаров

    RemovedProduct *removedProductTemplate;

public:

    HashTable(int size) : size(size) {
        products.resize(size);
        removedProductTemplate = new RemovedProduct();
    }

    int getSize() const {
        return size;
    }

    int getFilled() const {
        return filled;
    }

    int getRemoved() const {
        return removed;
    }


    int getHash(int number){
        /**
         * Хэш функция
         */
        return number % size;
    }

    void rehash(){
        /**
         * Метод рехеширования (увеличиваем размер таблицы в 2 раза и убираем удаленные элементы)
         */
        vector<Product*> buffer = products; // сохраняем старый массив
        products.clear(); // очищаем поле
        filled = 0; // обновляем значения
        removed = 0;
        size *= 2; // увеличиваем размер
        products.resize(size);
        // добавляем с проверкой на валидность
        for (auto p: buffer){
            if (p && !p->isRemoved()) push(p);
        }
    }

    bool push(Product *product){
        /**
         * Метод добавления в таблицу
         */
        // проверяем переполнение таблицы
        if (double (filled + removed) / float(size) > MAX_FILLED) rehash();

        // проверка уникальности номера
        for (auto p: products)
            if (p && p->getNumber() == product->getNumber())
                return false;

        int address;
        int i = 0;
        while (true){
            address = (getHash(product->getNumber()) + C * i + D * i * i) % size;
            if (products[address] == NULL){
                products[address] = product;
                filled++;
                return true;
            }
            ++i;
        }
    }

    int getAddressByNumber(int key){
        /**
         * Получение адреса элемента по ключу (по номеру товара)
         */
        for (int i = 0; i < size; ++i) {
            int address = (getHash(key) + C * i + D * i * i) % size;
            if (products[address] && products[address]->getNumber() == key)
                return address;
        }
        return -1;
    }

    Product* getProductByNumber(int key) {
        /**
         * Получение элемента по ключу (по номеру товара)
         */
        int address = getAddressByNumber(key);
        if (address != -1) return products[address];
        else cout << "Такого товара не существует" << endl;
    }

    bool removeProductByNumber(int key) {
        /**
         * Удаление товара по ключу
         */
        int address = getAddressByNumber(key);
        if (address != -1) {
            products[address] = removedProductTemplate;
            removed++;
            filled--;
            return true;
        } else {
            return false;
        }
    }

    void print(){
        /**
         * Метод для вывода хэш таблицы
         */
        int numSize = to_string(size).size();

        cout << "Size: " << size << " | Filled: " << filled << " | Deleted: " << removed << " \n";

        cout << setw(20) << left <<"Number"<< setw(20) << left << "Product"<< setw(20) << left << "Price" << endl;

        // Table data output
        for (int i = 0; i < size; ++i)
            if (products[i] && !products[i]->isRemoved())
                cout << setw(20) << left << products[i]->getNumber()<< setw(20) << left << products[i]->getName()<< setw(20) << left << products[i]->getPrice() << endl;
    }


};
