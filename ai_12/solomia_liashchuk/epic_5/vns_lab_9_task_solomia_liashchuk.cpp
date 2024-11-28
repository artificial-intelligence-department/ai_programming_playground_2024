#include <iostream>
#include <fstream>
#include <cstring>
int count_words(const char* str)
{
    int word_count = 0;
    bool in_word = false;

    while (*str) 
    {
        if (*str != ' ' && *str != '\n' && *str != '\t') 
        {
            if (!in_word) 
            {
                in_word = true;
                word_count++;
            }
        }
        else 
        {
            in_word = false;
        }
        str++;
    }

    return word_count;
}

int count_vowels(const char* word)
{
    int vowels = 0;
    const char* vowels_set = "aeiouAEIOUаеиіоуяюєїАЕИІОУЯЮЄЇ";

    while (*word) 
    {
        if (strchr(vowels_set, *word)) 
        {
            vowels++;
        }
        word++;
    }

    return vowels;
}

int find_word_with_most_vowels(const char* str)
{
    int max_vowels = 0;
    int word_index = 0;
    int current_index = 0;

    const char* word_start = str;
    while(*str) 
    {
        if(*str == ' ' || *str == '\n' || *str == '\t' || *(str + 1) == '\0') 
        {
            if(*(str + 1) == '\0') 
                str++; 

            char word[256];
            strncpy(word, word_start, str - word_start);
            word[str - word_start] = '\0';

            int vowels = count_vowels(word);
            if(vowels > max_vowels) 
            {
                max_vowels = vowels;
                word_index = current_index + 1;
            }

            current_index++;
            word_start = str + 1;
        }
        str++;
    }

    return word_index;
}

int main()
{
    FILE *file1 = fopen("file.task9.txt", "w");
    if(file1 == NULL)
    {
        printf("Error: Unable to create file F1\n");
        return 1;
    }

    fprintf(file1, "Хто тримає цей район?.\n");
    fprintf(file1, "Пес Патрон, пес Патрон.\n");
    fprintf(file1, "Два слова.\n");
    fprintf(file1, "Хто крутіший за iPhone?.\n");
    fprintf(file1, "Два слова.\n");
    fprintf(file1, "Пес Патрон, пес Патрон.\n");
    fprintf(file1, "Два слова.\n");
    fprintf(file1, "Хто не ходить на газон?.\n");
    fprintf(file1, "Пес Патрон, пес Патрон.\n");
    fprintf(file1, "Два слова.\n");
    fprintf(file1, "В розмінуванні чемпіон.\n");
    fprintf(file1, "Пес Патрон, пес Патрон.\n");
    fprintf(file1, "Два слова.\n");
    fprintf(file1, "Пес Патрон, пес Патрон.\n");
    fprintf(file1, "Таких нам треба батальйон.\n");

    fclose(file1);

    file1 = fopen("file.task9.txt", "r");
    if(file1 == NULL)
    {
        printf("Error: Unable to open file F1 for reading\n");
        return 1;
    }

    printf("Contents of file1.txt:\n");
    char line[256];
    while (fgets(line, sizeof(line), file1))
    {
        printf("%s", line);
    }
    fclose(file1);

    FILE *file2 = fopen("file.task9.txt2", "w");
    if(file2 == NULL)
    {
        printf("Error: Unable to create file F2\n");
        return 1;
    }

    file1 = fopen("file.task9.txt", "r");
    if(file1 == NULL)
    {
        printf("Error: Unable to read file1\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file1) != NULL) 
    {
        if (count_words(line) > 2) 
        {
            fputs(line, file2);
        }
    }

    fclose(file1);
    fclose(file2);

    printf("Content successfully copied from file.task9.txt to file2.task9.txt\n");

    file2 = fopen("file.task9.txt2", "r");
    if(file2 == NULL)
    {
        printf("Error: Unable to open file2 for reading\n");
        return 1;
    }

   while(fgets(line, sizeof(line), file2))
    {
        printf("%s", line);
    }
    fclose(file2); 

    file2 = fopen("file.task9.txt2", "r");
    if (file2 == NULL)
    {
        printf("Error: Unable to open file F2 for reading\n");
        return 1;
    }

    printf("\nFinding word with the most vowels in file2.txt:\n");
    while (fgets(line, sizeof(line), file2)) 
    {
        int max_vowel_word_index = find_word_with_most_vowels(line);
        printf("In line: \"%s\" -> Word #%d has the most vowels.\n", line, max_vowel_word_index);
    }

    fclose(file2);


    return 0;
}