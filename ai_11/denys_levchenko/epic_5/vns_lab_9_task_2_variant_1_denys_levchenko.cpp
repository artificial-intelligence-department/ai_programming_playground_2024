#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int count_words(const char *line);
int line_matches_condition(const char *line);

int main() {
    FILE *f1, *f2;
    char line[256];
    int current_line = 1;
    int N1 = 1; 
    int N2 = 5; 

    if ((f1 = fopen("F1.txt", "r")) == NULL) {
        printf("Помилка відкриття файлу F1.txt\n");
        return 1;
    }

    if ((f2 = fopen("F2.txt", "w")) == NULL) {
        printf("Помилка відкриття файлу F2.txt\n");
        fclose(f1);
        return 1;
    }

    while (fgets(line, 256, f1) != NULL) {
        if (current_line >= N1 && current_line <= N2 && line_matches_condition(line)) {
            fputs(line, f2);
        }
        current_line++;
    }

    fclose(f1);
    fflush(f2);
    fclose(f2);

    if ((f2 = fopen("F2.txt", "r")) == NULL) {
        printf("Помилка відкриття файлу F2.txt\n");
        return 1;
    }

    if (fgets(line, 256, f2) != NULL) {
        int word_count = count_words(line);
        printf("Кількість слів у першому рядку файлу F2: %d\n", word_count);
    } else {
        printf("Файл F2 порожній або помилка читання\n");
    }

    fclose(f2);
    return 0;
}


int line_matches_condition(const char *line) {

    while (isspace((unsigned char)*line)) line++;
    int len = strlen(line);
    while (len > 0 && isspace((unsigned char)line[len - 1])) len--;

    return (len >= 2 && strncmp(line, "А", 2) == 0 && strncmp(&line[len - 2], "З", 2) == 0);
}

int count_words(const char *line) {
    int count = 0;
    int in_word = 0;

    while (*line) {
        if (isspace((unsigned char)*line)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        line++;
    }

    return count;
}
