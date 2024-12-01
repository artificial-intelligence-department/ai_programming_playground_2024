#include <iostream>
using namespace std;

int main() {
    double numbers[5]; //Використав одновимірний масив для зберігання дробових чисел
    double sum = 0.0;

    cout << "Введіть 5 дробових чисел:" << endl;
    for (int i = 0; i < 5; ++i) 
    {
        cout << "Число " << i + 1 << ": ";
        cin >> numbers[i];
        sum += numbers[i];
    }

    double average = sum / 5.0;
    cout << "Середнє арифметичне: " << average;

    return 0;
}