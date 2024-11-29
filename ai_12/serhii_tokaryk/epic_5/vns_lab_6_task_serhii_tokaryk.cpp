#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int countWords(const char *str) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '.') { 
            if (!inWord) {
                count++;
                inWord = true; 
            }
        } else {
            inWord = false; 
        }
    }

    return count;
}

int main() {
    char s[256];
    //gets(s) 
    printf("Введіть текст (не більше 255 символів, закінчується крапкою): ");
    if (fgets(s, sizeof(s), stdin) == NULL) { 
        printf("Помилка введення!\n");
        return 1;
    }

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    int wordCount = countWords(s);
    printf("Кількість слів у рядку: %d\n", wordCount);

    return 0;
}
