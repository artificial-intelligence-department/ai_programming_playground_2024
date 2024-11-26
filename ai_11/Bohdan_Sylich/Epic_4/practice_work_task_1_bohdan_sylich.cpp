#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    string str = to_string(number);
    return isPalindrome(str, 0, str.size() - 1);
}

int main() {
    string str;
    cout << "Введіть слово для перевірки: ";
    cin >> str;
    if (isPalindrome(str, 0, str.size() - 1)) {
        cout << "Рядок \"" << str << "\" є паліндромом." << endl;
    } else {
        cout << "Рядок \"" << str << "\" не є паліндромом." << endl;
    }

    int number;
    cout << "Введіть число для перевірки: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << "Число " << number << " є паліндромом." << endl;
    } else {
        cout << "Число " << number << " не є паліндромом." << endl;
    }

    return 0;
}
