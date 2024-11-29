#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Введіть число: ";
    cin >> number;
    if (number < 0) {
        number = -number;
    }

    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    cout << "Сума цифр числа: " << sum << endl;

    return 0;
}
