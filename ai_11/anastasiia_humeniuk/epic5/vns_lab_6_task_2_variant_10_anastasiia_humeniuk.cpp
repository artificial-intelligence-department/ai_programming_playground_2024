#include <stdio.h> //printf fgets
#include <string.h>//strtok strcat strcspn
#include <ctype.h> //isalpha isdigit

int wordType(const char *word) {
    int hasLetters = 0, hasDigits = 0;
    for (int i = 0; word[i]; i++) {
        if (isalpha(word[i])) hasLetters = 1;
        if (isdigit(word[i])) hasDigits = 1;
    }
    if (hasLetters && hasDigits) return 2; 
    if (hasLetters) return 1;
    if (hasDigits) return 0;
    return -1;
}

int main() {
    const int bufferSize = 255; 
    char s[bufferSize], onlyDigits[bufferSize] = "", onlyLetters[bufferSize] = "", mixed[bufferSize] = "";
    
    printf("Input text: ");
    fgets(s, bufferSize, stdin); 
    s[strcspn(s, "\n")] = 0; 

    char *word = strtok(s, " ");
    while (word != NULL) {
        switch (wordType(word)) {
            case 0: strcat(onlyDigits, word); strcat(onlyDigits, " "); break;
            case 1: strcat(onlyLetters, word); strcat(onlyLetters, " "); break;
            case 2: strcat(mixed, word); strcat(mixed, " "); break;
        }
        word = strtok(NULL, " ");
    }

    printf("Output text: %s%s%s\n", onlyDigits, onlyLetters, mixed);
    
    return 0;
}
