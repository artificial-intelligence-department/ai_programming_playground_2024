#include <iostream>
#include <cstring> // Для функції gets
using namespace std;

// Функція для перевірки, чи є слово паліндромом
bool isPalindrome(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Функція для друку паліндромів у рядку
void printPalindrome(char* str) {
    char* word = strtok(str, " .");
    while (word != nullptr) {
        int len = strlen(word);
        if (isPalindrome(word, 0, len - 1)) {
            cout << word << endl;
        }
        word = strtok(nullptr, " .");
    }
}

int main() {
    char s[256];
    cout << "Введіть рядок: ";
    gets(s); // Використовуємо gets для зчитування рядка

    printPalindrome(s); // Викликаємо функцію для друку паліндромів

    return 0;
}
