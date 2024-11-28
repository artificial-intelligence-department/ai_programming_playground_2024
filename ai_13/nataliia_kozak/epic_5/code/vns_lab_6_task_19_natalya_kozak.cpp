#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool isIdentifier(const char* word) {
    if (!islower(word[0]) && word[0] != '_') 
        return false;
    for (int i = 1; word[i] != '\0'; ++i) {
        if (!isalnum(word[i]) && word[i] != '_') 
            return false;
    }
    return true;
}

int main() {
    char s[255]; 
    cout << endl << "Input text (<255 characters, ends with period):" << endl;

    gets(s);
    char result[255] = "";
    char* word = strtok(s, " "); 

    while (word != nullptr) {
        if (isIdentifier(word)) {
            strcat(result, word); // Додати ідентифікатор до результату
            strcat(result, " ");  // Додати пробіл між словами
        }
        word = strtok(nullptr, " "); // Отримати наступне слово
    }

    cout << "Результат: " << result << endl;

    return 0;
}
