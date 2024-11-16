//ідентифікатори та мінус слова-цифри
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void Print(char s[]) {
    char* token;
    token = strtok(s," ");

    if(!isdigit(token[0])) {
        int numcount = 0;   //рахуємо цифри в кожному слові
        for(int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
            if(isdigit(token[i])) {
                numcount++;
            }
        }
        if(numcount < strlen(token)) {
            puts(token);
        }
    }
    while(token != NULL) {
        token = strtok(NULL, " ");
        if(token != NULL && !isdigit(token[0])) {
        int numcount = 0;
            for(int i = 0; i < strlen(token); i++) {
                token[i] = tolower(token[i]);
                if(isdigit(token[i])) {
                    numcount++;
                }
            }
            if(numcount < strlen(token)) {
                puts(token);
            }
        }
    }
}

int main() {

    char s[255];
    gets(s);

    Print(s);

    return 0;
}