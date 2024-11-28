#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORDS 100

void copy(FILE *F1, FILE *F2)
{
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), F1))
    {
        char copy[MAX_LINE];
        strcpy(copy, line); 

        char *words[MAX_WORDS];
        int count = 0;

        // Розбиття рядка на слова
        char *token = strtok(line, " \t\n");
        while (token && count < MAX_WORDS)
        {
            words[count++] = token;
            token = strtok(NULL, " \t\n");
        }

        // Перевірка на дублікати
        for (int i = 0; i < count; i++)
            for (int j = i + 1; j < count; j++)
                if (strcmp(words[i], words[j]) == 0)
                {
                    fputs(copy, F2);
                    break;
                }
    }
}

void max_a(FILE *F1)
{
    rewind(F1);
    char line[MAX_LINE];
    int current_line = 1;
    while (fgets(line, sizeof(line), F1))
    {
        char *token;
        int maxCount = 0;
        int maxWordNumber = 0;
        int wordNumber = 0;

        // Розбиття рядка на слова
        token = strtok(line, " \t\n");
        while (token)
        {
            wordNumber++;
            int countA = 0;

            // Підрахунок кількості 'А'/'а' у слові
            for (int i = 0; token[i]; i++)
                if (tolower(token[i]) == 'a')
                    countA++;

            // Оновлення максимуму
            if (countA > maxCount)
            {
                maxCount = countA;
                maxWordNumber = wordNumber;
            }

            token = strtok(NULL, " \t\n");
        }

        // Виведення результату для рядка
        if (maxWordNumber > 0)
            printf("In line: №%i word #%d has the most 'А' (%d).\n", current_line, maxWordNumber, maxCount);
        current_line++;
    }
}

int main()
{
    char file1[] = "F1.txt";
    char file2[] = "F2.txt";
    FILE *F1 = fopen(file1, "r");
    FILE *F2 = fopen(file2, "w");

    if (!F1 || !F2)
    {
        printf("Error opening file\n");
        return 1;
    }

    copy(F1, F2);
    max_a(F1);
    fclose(F1);
    fclose(F2);
    return 0;
}
