#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define VOWELS "AEIOUaeiou"

bool hasDuplicateWords(const char *line) {
    char temp[256];
    strcpy(temp, line); // копіюємо рядок у тимчасовий буфер
    char* words[50];//масив адрес де зберігаються адреси токенів
    int count = 0;

    char* token = strtok(temp, " .,"); //роздільники пробіл крапка кома
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " .,");//робим NULL шоб while сприйняв рядок знов
    }

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                return true; // Знайдено повтор
            }
        }
    }
    return false;
}




// Функція для підрахунку голосних у рядку
int countVowels(const char *line) {
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (strchr(VOWELS, line[i]) != NULL) {//до першої появи голосної
            count++;
        }
    }
    return count;
}

int main() {
    FILE *f1, *f2;
    char line[MAX_LINE];
    char lastLine[MAX_LINE] = "";
    
    // Створення файлу F1 і запис у нього даних
    if ((f1 = fopen("F1.txt", "w")) == NULL) {
        perror("Помилка при створенні F1");
        exit(1);
    }

    printf("Запишіть текст у файл F1 (не менше 10 рядків, завершення CTRL+Z+ENTER):\n");
    while (fgets(line, MAX_LINE, stdin) != NULL) {//fgets читає зара шо ми вводим
        fputs(line, f1);//переносим у F1 по реченню
    }
    fclose(f1);




    //файл F1 для читання і F2 для запису
    if ((f1 = fopen("F1.txt", "r")) == NULL) {
        perror("Помилка при відкритті F1 для читання");
        exit(1);
    }

    if ((f2 = fopen("F2.txt", "w")) == NULL) {
        perror("Помилка при створенні F2");
        fclose(f1);
        exit(1);
    }

    //копіюємо рядки з повторюваними словами
    while (fgets(line, MAX_LINE, f1) != NULL) {//читання по реченню
        if (hasDuplicateWords(line)) {
            fputs(line, f2);//копіюєм шо получили у F2
            strcpy(lastLine, line);  // Запам'ятовуємо останній рядок
        }
    }
    fclose(f1);
    fclose(f2);

    //кількість голосних у останньому рядку F2
    if (strlen(lastLine) > 0) {
        int vowels = countVowels(lastLine);
        printf("Кількість голосних у останньому рядку файлу F2: %d\n", vowels);
    } else {
        printf("Файл F2 порожній або немає рядків із повторюваними словами.\n");
    }

    return 0;
}
