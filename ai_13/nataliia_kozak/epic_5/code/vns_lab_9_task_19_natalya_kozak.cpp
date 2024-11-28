#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *F1, *F2;
    char o_line[50], *s;
    F1 = fopen("F1.txt", "w+");
    rewind(F1);
    if (F1 == 0)
    {
        printf("Error opening F1!\n");
        exit(1);
    }
    for (int i = 0; i < 10; i++)
    {
        fgets(o_line, 50, stdin);
        fputs(o_line, F1);
    }
    char first_word[50];
    rewind(F1);
    fscanf(F1, "%s", first_word);
    rewind(F1);

    F2 = fopen("F2.txt", "w+");
    bool need_to_w;
    char line[50];
    while (fgets(o_line, 50, F1) != 0)
    {
        strcpy(line, o_line);
        need_to_w = true;
        s = strtok(line, " ");
        while (s != NULL)
        {
            if (!strcmp(s, first_word))
            {
                need_to_w = false;
            }
            s = strtok(NULL, " ");
        }
        if (need_to_w)
        {
            fputs(o_line, F2);
        }
    }

    rewind(F2);
    fgets(o_line, 50, F2);
    int count = 0;
    for (int i = 0; o_line[i]!='\n'; i++)
    {
        if (o_line[i] == 'a' || o_line[i] == 'e' || o_line[i] == 'i' || o_line[i] == 'o' || o_line[i] == 'u' || o_line[i] == 'A' || o_line[i] == 'E' || o_line[i] == 'I' || o_line[i] == 'O' || o_line[i] == 'U' || o_line[i] == ' ')
        {
        }
        else
        {
            count++;
        }
    }
    printf("\nNumber of consonants: %d", count);

    return 0;
}