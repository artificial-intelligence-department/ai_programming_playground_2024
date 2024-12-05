#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool ident_check(char* word) {
    if (word[0] == '\0') return false;

    if (!isalpha(word[0]) && word[0] != '_') return 0;

    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_') 
            return false;
    }

    return true;
}

int main() {
    char str[256]; 
    cout << endl << "Enter a sentence: \n";
    gets(str);

    char res[256] = "";
    char* word = strtok(str, " "); 

    while (word != nullptr) {
        if (ident_check(word)) {
            strcat(res, word);
            strcat(res, " ");
        }
        word = strtok(nullptr, " ");
    }

    cout << "Result: " << res;

    return 0;
}