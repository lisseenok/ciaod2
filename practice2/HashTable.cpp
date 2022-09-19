#include <vector>
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
public:
    // хэш функция
    int getHash(int number){
        return number % size;
    }

    // метод добавления в таблицу
    bool push(Product *product){
        // добавить проверку переполнения
        // добавить проверку уникальности номера
        int address;
        for (int i = 0; i < size; ++i) {
            address = getHash(product->getNumber()) + C * i + D * i * i;
            if (products[address] == nullptr){
                products[address] = product;
                filled++;
                return true;
            }
        }
    }
};
