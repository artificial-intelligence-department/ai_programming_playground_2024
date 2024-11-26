#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    cout << "порівняння " << str[start] << " і " << str[end] << endl;
    if (str[start] != str[end]) {
        return false;
    }
    
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    int num = number; 
    int reverse = 0;
    while(number > 0){
        int digit = number%10;
        reverse = reverse * 10 + digit;
        number /=10;
    }
    return (num == reverse);
}

int main() {
    string word;
    cout << "Введіть слово: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "Слово є паліндромом" << endl;
    } 
    else {
        cout << "Слово не є паліндромом" << endl;
    }

    int Number;
    cout << "Введіть число: ";
    cin >> Number;
    if (isPalindrome(Number)) {
        cout << "Число є паліндромом" << endl;
    } 
    else {
        cout << "Число не є паліндромом" << endl;
    }

    return 0;
}