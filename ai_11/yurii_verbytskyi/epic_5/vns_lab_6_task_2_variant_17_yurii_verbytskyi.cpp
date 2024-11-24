#include <stdio.h>
#include <string.h>
#include <ctype.h>

int firstletter(char *word){
    return isalpha(word[0]);
}

int main(){

int maxlen = 255;
char str[maxlen + 1];
char *words[maxlen];
int k = 0;
printf("Enter line: \n");
gets(str); 

char *token = strtok(str, " ");  
while (token != NULL) {
    if (firstletter(token)) {  
        words[k++] = token;  
    }
    token = strtok(NULL, " "); 
}

for (int i = 0; i < k - 1; i++) {
    for (int j = i + 1; j < k; j++) {
        if (strcmp(words[i], words[j]) > 0) {  
            char *temp = words[i];
            words[i] = words[j];
            words[j] = temp;
        }
    }
}


printf("Sorted words:\n");
for (int i = 0; i < k; i++) {
    printf("%s\n", words[i]);
}

    return 0;
}
