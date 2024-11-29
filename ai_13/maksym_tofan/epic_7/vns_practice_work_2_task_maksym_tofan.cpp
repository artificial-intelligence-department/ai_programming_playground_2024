#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введіть кількість чисел: ";
    cin >> n;

    double sum = 0.0, num;

    for (int i = 0; i < n; i++) {
        cout << "Введіть число: ";
        cin >> num;
        sum += num;
    }

    double average = sum / n;
    cout << "Середнє арифметичне: " << average << endl;

    return 0;
}
