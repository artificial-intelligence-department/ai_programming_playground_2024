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

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    string word;
    cout << "Введіть слово для перевірки на паліндром: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " є паліндромом" << endl;
    } else {
        cout << word << " не є паліндромом" << endl;
    }
    
    int number;
    cout << "Введіть число для перевірки на паліндром: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << number << " є паліндромом" << endl;
    } else {
        cout << number << " не є паліндромом" << endl;
    }

    return 0;
}
