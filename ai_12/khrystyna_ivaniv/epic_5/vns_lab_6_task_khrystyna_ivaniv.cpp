#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void string_sort(char *string)
{

    char *word = strtok(string, " .");
    while (word != nullptr)
    {
        sort(word, word + strlen(word));
        cout << word << " ";
        word = strtok(nullptr, " .");
    }

    cout << "." << endl;
}

int main()
{
    const int max_lenght = 255;
    char string[max_lenght + 1];

    gets(string);
    string_sort(string);
    return 0;
}