#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;

    string minNumber = n;
    sort(minNumber.begin(), minNumber.end());

    // Переміщуємо першу ненульову цифру на початок, якщо є нуль на початку
    if (minNumber[0] == '0') {
        for (int i = 1; i < minNumber.size(); i++) {
            if (minNumber[i] != '0') {
                swap(minNumber[0], minNumber[i]);
                break;
            }
        }
    }

    string maxNumber = n;
    sort(maxNumber.begin(), maxNumber.end(), greater<char>());

    cout << minNumber << " " << maxNumber;

}
