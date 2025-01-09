#include <iostream>

using namespace std;

int main() {
    int count;
    cout << "Введіть кількість чисел: ";
    cin >> count;

    if (count <= 0) {
        cout << "Кількість чисел має бути більше нуля!" << endl;
        return 1;
    }

    double sum = 0.0, number;

    cout << "Введіть числа:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Число " << i + 1 << ": ";
        cin >> number;
        sum += number;
    }

    double average = sum / count;
    cout << "Середнє арифметичне: " << average << endl;
    
    return 0;
}