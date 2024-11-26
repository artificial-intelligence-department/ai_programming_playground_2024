#include <stdio.h>
#include <string.h>

void Coincidences(char str[]){
    char *token;
    token = strtok(str, " ");
    char *first_word = token;
    printf("The first word: %s\n", first_word);
    while(token != NULL){
        token = strtok(NULL, " ");
        if(token != NULL && strcmp(first_word, token) == 0){
            printf("%s\n", token);
        }
    }
}
int main() {
    char s[256];
    char space = ' ';
    fgets(s, sizeof(s), stdin);
    s[strlen(s) - 1] = ' ';
    Coincidences(s);
    return 0;
}
