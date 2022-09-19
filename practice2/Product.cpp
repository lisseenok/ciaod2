#include <string>

using namespace std;
/**
 * Открытая адресация (квадратич- ное пробирование)
Товар: код – шестиразрядное число, название, цена
 */
class Product {
private:
    int number;
    string name;
    int price;
public:
    Product(int number, string name, int price) : number(number), name(name), price(price){}

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        Product::number = number;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Product::name = name;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        Product::price = price;
    }
};
