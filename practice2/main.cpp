#include <iostream>
#include "HashTable.cpp"

using namespace std;

int main(){
    HashTable table = HashTable(10);
    int ex = -1;
    int numBuff;
    int priceBuff;
    string nameBuff;
    string strBuff;
    while (ex) {
        cout << "1. Ввести данные\n"
                "2. Показать таблицу\n"
                "3. Получить товар по номеру\n"
                "4. Удалить товар по номеру\n"
                "5. Информация о таблице\n"
                "0. Exit\n";
        cin >> ex;
        switch (ex) {
            case 1:
                cout << "Введите номер товара, наименование и цену:\n";
                cin >> numBuff >> nameBuff >> priceBuff;
                if (!table.push(new Product(numBuff, nameBuff, priceBuff)))
                    cout << "Такой товар уже существует.\n";
                break;
            case 2:
                table.print();
                break;
            case 3:
                cout << "Введите номер товара:\n";
                cin >> numBuff;
                Product *product;
                product = table.getProductByNumber(numBuff);
                if (product) {
                    cout << "Товар с номером: " << product->getNumber() << " Наименование: " << product->getName() << " Цена: " << product->getPrice() << endl;
                } else {
                    cout << "Товара с таким номером не существует.\n";
                }
                break;
            case 4:
                cout << "Введите номер товара, который необходимо удалить:\n";
                cin >> numBuff;
                if (!table.removeProductByNumber(numBuff))
                    cout << "Товара с таким номером не существует.\n";
                break;
            case 5:
                cout << "Размер: " << table.getSize() << " | Заполнено: " << table.getFilled() << "Удалено: " << table.getRemoved() << endl;
                break;
            case 0:
                cout << "Работа программы завершена\n";
                break;
            default:
                cout << "Команда не найдена, пожалуйста, повторите ввод. \n";
                break;
        }
    }
    return 0;
}

