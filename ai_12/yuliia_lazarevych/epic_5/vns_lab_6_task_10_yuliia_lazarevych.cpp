#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>

using namespace std;

bool isDigitOnly(const char* word) {
    for (int i = 0; word[i]; i++) {
        if (!isdigit(word[i])) return false;
    }
    return true;
}

bool isAlphaOnly(const char* word) {
    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i])) return false;
    }
    return true;
}

int main() {
    char s[256];
    cout << "Введіть текст (максимум 255 символів): ";
    gets(s);

    vector<string> digits_only, letters_only, mixed;

    char* word = strtok(s, " ");
    while (word != nullptr) {
        int len = strlen(word);
        if (word[len - 1] == '.') {
            word[len - 1] = '\0';
        }

        if (isDigitOnly(word)) {
            digits_only.push_back(word);
        } else if (isAlphaOnly(word)) {
            letters_only.push_back(word);
        } else {
            mixed.push_back(word);
        }

        word = strtok(nullptr, " ");
    }

    cout << "Результат: ";
    for (int i=0; i<digits_only.size(); i++) cout << digits_only[i] << " ";
    for (int i=0; i<letters_only.size(); i++) cout << letters_only[i] << " ";
    for (int i=0; i<mixed.size(); i++) cout << mixed[i] << " ";

    return 0;
}

