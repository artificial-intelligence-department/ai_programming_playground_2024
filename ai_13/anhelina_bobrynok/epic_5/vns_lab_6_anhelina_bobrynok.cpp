#include <iostream>
#include <cstring>
#include <cctype> 

using namespace std;

bool hasOneDigit(const char* word) {
    int digitCount = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (isdigit(word[i])) {
            ++digitCount;
        }
        if (digitCount > 1) return false;
    }
    return digitCount == 1;
}

int main() {
    char s[256];

    cout << "Введіть текст (не більше 255 символів, закінчити крапкою): ";
    cin.getline(s, 256);

    int len = strlen(s);
    if (s[len - 1] == '.') {
        s[len - 1] = '\0';
    }

    char* word = strtok(s, " ");
    cout << "Слова, які містять рівно одну цифру:\n";

    while (word != nullptr) {
        if (hasOneDigit(word)) {
            cout << word << endl;
        }
        word = strtok(nullptr, " ");
    }

    return 0;
}

