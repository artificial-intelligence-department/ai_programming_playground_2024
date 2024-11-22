#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool hasLettersAndDigits(const char* word) {
    bool hasLetter = false, hasDigit = false;

    for (int i = 0; word[i] != '\0'; ++i) {
        if (isalpha(word[i])) hasLetter = true; 
        if (isdigit(word[i])) hasDigit = true;  
    }

    return hasLetter && hasDigit;  
}

int main() {
    char input[256]; 
    cout << "Введіть рядок (до 255 символів, закінчується крапкою): ";
    gets(input);  

    char result[256] = "";  
    char* word = strtok(input, " "); 

   
    while (word != nullptr) {
        if (hasLettersAndDigits(word)) {  
            strcat(result, word);       
            strcat(result, " ");         
        }
        word = strtok(nullptr, " ");  
    }

  
    int len = strlen(result);
    if (len > 0 && result[len - 1] == ' ') {
        result[len - 1] = '\0';
    }

    cout << "Оброблений рядок: " << result << endl;  
    return 0;
}
// g++ -o myprogram vns_lab_6_task_lesia_liashko.cpp
// ./myprogram