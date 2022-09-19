#include <iostream>
#include <random>
#include <fstream>
#include <ctime>

using namespace std;
void generate_file() {
    int n;
    ofstream out;

    auto rng = default_random_engine {}; // генерация

    cout << "Введите количество чисел: ";
    cin >> n;

    vector<int> nums = vector<int>(n);

    out.open("input.txt");

    iota(nums.begin(), nums.end(), 0); // заполнили массив 0
    shuffle(nums.begin(), nums.end(), rng); //перетасуем массив

    // запись в файл
    for(int i = 0; i < n; i++) {
        out << nums[i] << "\n";
    }
    out.close();
}

int main() {
    // генерируем файл
    generate_file();

    // засекаем время
    unsigned int start_time =  clock();

    ifstream in;
    in.open("input.txt");

    const int size_of_block = 7; // кол-во ячеек в массиве
    unsigned char block = 0;
    int num = 0;
    vector<unsigned char> array = vector<unsigned char>(0);

    while(in >> num) {
        int block_n = num / 8; // вычисляем в какую восьмерку
        int sz = array.size() - 1;
        if (block_n > sz) { // создаем блоки
            for(int j = 0; j < block_n - sz; j++) array.push_back(block);
        }
        // запись числа в блок
        array[block_n] = array[block_n] | 1 << (size_of_block - num % 8);
    }
    in.close();

    ofstream out;
    out.open("output.txt");

    int len = array.size() * 8;
    for(int i = 0; i < len; i++) {
        // запись в файл
        // сдвигаем каждый блок
        if ((array[i / 8] >> (size_of_block - i % 8)) & 1) out << i << "\n";
    }
    out.close();

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    int kbits = (array.size() * sizeof(unsigned char)) / 1024;

    cout << "Потраченное время: " << search_time / 1000.0 << "ms" << "\n";
    cout << "Потраченная оперативная память:  " << kbits << " kb" << "\n";

}