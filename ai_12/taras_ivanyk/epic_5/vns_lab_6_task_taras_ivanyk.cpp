#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cctype>

using namespace std;

int main() {
    char myStr[256];
    cout << "Enter a string : ";
    gets(myStr);  

    char result[256] = "";
    char* token = strtok(myStr, " "); 

    bool first_word = true; 

    while (token != nullptr) {
        bool only_digit = true;

        for (int i = 0; i < strlen(token); i++) {
            if (!isdigit(token[i])) {
                only_digit = false;
                break;
            }
        }
        if (!only_digit) {
            token[0] = tolower(token[0]); 
            if (!first_word) {
                strcat(result, " "); // додаємо пробіли
            }
            strcat(result, token); 
            first_word = false;
        }
        token = strtok(nullptr, " "); //перехід до нступного слова
    }
    cout << result << endl;
    return 0;
}
