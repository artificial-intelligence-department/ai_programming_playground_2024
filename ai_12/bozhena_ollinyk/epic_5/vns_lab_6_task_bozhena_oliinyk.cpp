#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

void convertToWords(char *sent, char words[][255], int &wordCount)
{
    char *w = strtok(sent, " ");
    wordCount = 0;

    while (w != nullptr)
    {
        strcpy(words[wordCount++], w);
        w = strtok(nullptr, " ");
    }
}
int main()
{
    char sentence[255];

    cout << "Введіть рядок: ";
    fgets(sentence, sizeof(sentence), stdin);

    int length = sizeof(sentence);
    if (length > 0 && sentence[length - 1] == '.')
    {
        sentence[length - 1] = '\0';
    }

    char words[50][255];
    int wordCount = 0;

    convertToWords(sentence, words, wordCount);
    cout << "Слова, що співпадають з першим словом (" << words[0] << "):" << endl;
    for (int i = 0; i < wordCount; i++)
    {
        if (strcmp(words[0], words[i]) == 0)
        {
            cout << words[i] << endl;
        }
    }

    return 0;
}

