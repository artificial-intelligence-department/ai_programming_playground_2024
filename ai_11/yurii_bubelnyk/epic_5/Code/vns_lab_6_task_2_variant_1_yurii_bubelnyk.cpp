#include <stdio.h>
#include <string.h>

void Find(char s[]);

int main() {
    char s[256];
    
    fgets(s, sizeof(s), stdin);  // Зчитуємо рядок

    Find(s);  // Виводимо зчитаний рядок

    return 0;
}

void Find(char s[]){
    char* token = strtok(s, " ");
    char largestWord[256] = "";
    char smallestWord[256] = "";

    int largestLength = 0;
    int smallestLength = strlen(token);

    while( token != NULL){
        int tokenLength = strlen(token);
        printf("%s\n", token);

        if(tokenLength > largestLength){
            largestLength = tokenLength;
            strcpy(largestWord, token);
        }
            
        if(tokenLength < smallestLength){
            smallestLength = tokenLength;
            strcpy(smallestWord, token);
        }
            
        token = strtok(NULL, " ");
    }
    printf("%s\n", largestWord);
    printf("%s\n", smallestWord);
    
}
