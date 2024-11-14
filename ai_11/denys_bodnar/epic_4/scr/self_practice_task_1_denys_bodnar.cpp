#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введіть кількість чисел: ";
    cin >> n;

    double* numbers = new double[n];

    cout << "Введіть " << n << " чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Число " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }
    double average = sum / n;

    cout << "Середнє значення: " << average << endl;

    delete[] numbers;

    return 0;
}
