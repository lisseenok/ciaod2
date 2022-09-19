#include <iostream>


using namespace std;

// пункт б
void second_foo() {
    unsigned char x=191; //8-разрядное двоичное число 10111111
    unsigned char maska = 1; //1=00000001 – 8-разрядная маска
    x = x | (maska<<6); //результат x=64
    cout << (int) x << endl;
}
// пункт а
void first_foo() {
    unsigned char x=16; //8-разрядное двоичное число 00010000
    unsigned char maska = 1; //1=00000001 – 8-разрядная маска
    x = x & (~ (maska<<4)); //результат x=239
    cout << (int) x << endl;
}
// пункт в
void third_foo(){
    unsigned int x = 255;
    const int n = sizeof(int)*8; // =32 - кол-во разрядов в инте
    unsigned maska = (1 << n - 1); // 1 в 32 разряде
    cout << "Начальный вид маски: " << bitset<n> (maska) << endl;
    cout << "Результат: ";
    for (int i = 1; i <= n; ++i) {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
    cout << endl;
}

int main() {
    third_foo();
    return 0;
}
