#include <iostream>
#include <cstring>

#define BUFSIZE 256

bool identical_words(const char* line)
{
    char* line2 = new char[strlen(line)];
    strcpy(line2, line);
    bool found = false;
    int count = 0;
    char* words[BUFSIZE];
    char* word = strtok(line2, " .,!?\n");
    words[0] = word;
    for (int i = 1; (i < BUFSIZE); i++)
    {
        word = strtok(NULL, " .,!?\n");
        if (!word) break;
        count++;
        words[i] = word;
    }
    for (int i = 1; i <= count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (!strcmp(words[i], words[j]))
            {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    return found;
}

int number_of_words_with_most_digits(char* line)
{
    bool found = false;
    int count = 0;
    char* words[BUFSIZE];
    char* word = strtok(line, " .,!?\n");
    words[0] = word;
    for (int i = 1; (i < BUFSIZE); i++)
    {
        word = strtok(NULL, " .,!?\n");
        if (!word) break;
        count++;
        words[i] = word;
    }
    int digits, max_i, max_digits = 0;
    for (int i = 0; i <= count; i++)
    {
        digits = 0;
        for (int j = 0; j < sizeof(words[i]); j++)
        {
            if (isdigit(words[i][j]))
            {
                digits++;
            }
        }
        if (digits > max_digits) 
        {
            max_digits = digits;
            max_i = i;
        }
    }
    return max_i + 1;
}

int main()
{
    FILE* in = fopen("lab9_in.dat", "r");
    FILE* out = fopen("lab9_out.dat", "w");
    if (!in || !out) 
    {
        std::cout << "Error while opening files!";
        exit(1);
    }
    char line[BUFSIZE];

    while (fgets(line, sizeof(line), in))
    {
        if (identical_words(line)) fputs(line, out);
        std::cout << number_of_words_with_most_digits(line) << std::endl;
    }
    fclose(in);
    fflush(out);
    fclose(out);
}