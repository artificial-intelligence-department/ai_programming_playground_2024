// var 13
#include <iostream>
using namespace std;

int main() {
    int n; // int variable
    double sum = 0.0, number;

    cout << "Введіть кількість чисел: ";
    cin >> n;
    int i = 1;

    while(i <= n) {
        cout << "Введіть число " << i << ": ";
        cin >> number;
        sum += number;
        i++;
    }

    double average = sum / n;
    cout << "Середнє арифметичне введених чисел: " << average << endl;
}
