#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& text) {
    string reversedText = text;
    reverse(reversedText.begin(), reversedText.end());
    return text == reversedText;
}

bool isPalindrome(int value) {
    string valueStr = to_string(value);
    string reversedValueStr = valueStr;
    reverse(reversedValueStr.begin(), reversedValueStr.end());
    return valueStr == reversedValueStr;
}

int main() {
    string inputText;
    cout << "Введіть слово для перевірки: ";
    cin >> inputText;
    if (isPalindrome(inputText)) {
        cout << "Слово є паліндромом." << endl;
    } else {
        cout << "Слово не є паліндромом." << endl;
    }

    int inputNumber;
    cout << "Введіть число: ";
    cin >> inputNumber;
    if (isPalindrome(inputNumber)) {
        cout << "Число є паліндромом." << endl;
    } else {
        cout << "Число не є паліндромом." << endl;
    }

    return 0;
}
