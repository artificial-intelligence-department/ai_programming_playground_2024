#include <iostream>
#include <string>

using namespace std;

// Загадкове число
int main() {
    string input;
    cin >> input;

    string minNumber = input;
    string maxNumber = input;

    for (size_t i = 0; i < minNumber.length(); i++) {
        if (minNumber[i] == '*') {
            if (i == 0) {
                minNumber[i] = '1';
            } else {
                minNumber[i] = '0';
            }
        }
    }

    for (size_t i = 0; i < maxNumber.length(); i++) {
        if (maxNumber[i] == '*') {
            maxNumber[i] = '9';
        }
    }

    cout << minNumber << " " << maxNumber << endl;

    return 0;
}
