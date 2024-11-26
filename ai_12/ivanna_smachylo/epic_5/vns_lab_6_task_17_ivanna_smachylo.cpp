#include <stdio.h>
#include <string.h>
#include <ctype.h>

void SortWords(char str[]) 
{
    char *words[256];
    int count = 0;
    char *token;

    token = strtok(str, " .");
    while (token != NULL) 
    {
        if (isalpha(token[0])) 
        { 
            words[count++] = token;
        }
        token = strtok(NULL, " .");
    }

    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (strcmp(words[i], words[j]) > 0) 
            {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    printf("Words in alphabetical order: \n");
    for (int i = 0; i < count; i++) 
    {
        printf("%s\n", words[i]);
    }
}

int main() 
{
    char s[256] = "banana apple strawberry fruits."; 

    SortWords(s);

    return 0;
}
