#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Enter two single-digit numbers: ";
    cin >> num1 >> num2;

    if (num1 < 1 || num1 > 9 || num2 < 1 || num2 > 9) {
        cout << "Please enter only single digits from 1 to 9.\n";
        return 1;
    }

    int correctAnswer = num1 * num2;

    int userAnswer;
    cout << "How much will be " << num1 << " * " << num2 << "? ";
    cin >> userAnswer;

    if (userAnswer == correctAnswer) {
        cout << "Correct!\n";
    } else {
        cout << "Wrong. Correct answer: " << correctAnswer << ".\n";
    }

    return 0;
}
