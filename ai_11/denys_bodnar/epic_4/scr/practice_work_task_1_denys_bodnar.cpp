#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool Palindrom(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return Palindrom(str, start + 1, end - 1);
}

bool Palindrom(const string& str) {
    return Palindrom(str, 0, str.size() - 1);
}

bool Palindrom(int number) {
    if (number < 0) {
        return false;
    }
    string str = to_string(number);
    return Palindrom(str);
}

int main() {
    string word;
    int number;

    cout << "Введіть слово: ";
    cin >> word;
    if (Palindrom(word)) {
        cout << word << " є паліндромом." << endl;
    } else {
        cout << word << " не є паліндромом." << endl;
    }

    cout << "Введіть число: ";
    cin >> number;
    if (Palindrom(number)) {
        cout << number << " є паліндромом." << endl;
    } else {
        cout << number << " не є паліндромом." << endl;
    }
    
    return 0;
}
