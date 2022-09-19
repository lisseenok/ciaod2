#include <iostream>
using namespace std;

// пункт а (сортировка с помощью битового массива)
void first_foo(){
    int n;
    int buff;
    unsigned char x = 0;

    cout << "Введите кол-вл чисел (<=8): ";
    cin >> n;
    cout << "Введите числа (от 0 до 7): ";
    for (int i = 0; i < n; ++i) {
        cin >> buff;
        x = x | ((unsigned long long)1 << (buff));
    }
    bitset<8> b = bitset<8>(x);
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < 8; ++i) {
        if (b[i] == 1) cout << i << " ";
    }
}

// пункт б (для 64 бит)
void second_foo(){
    int n;
    int buff;
    unsigned long long x = 0;

    cout << "Введите кол-во чисел (<=64): ";
    cin >> n;
    cout << "Введите числа (от 0 до 63): ";
    for (int i = 0; i < n; ++i) {
        cin >> buff;
        x = x | ((unsigned long long) 1 << (buff));
    }
    bitset<64> b = bitset<64>(x);
    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < 64; ++i) {
        if (b[i] == 1) cout << i << " ";
    }
}

// пункт в (массив char)
void third_foo(){
    int n;
    int buff;
    unsigned char x[8];

    cout << "Введите кол-во чисел (<=64): ";
    cin >> n;

    for (int i = 0; i < 8; ++i){
        x[i] = 0;
    }

    cout << "Введите числа (от 0 до 63): ";
    for (int i = 0; i < n; ++i) {
        cin >> buff;
        x[buff / 8] = x[buff / 8] | (1 << (buff % 8));
    }

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((1 << j) & x[i]) cout << i * 8 + j << " ";
}

int main(){
    second_foo();
    return 0;
}

