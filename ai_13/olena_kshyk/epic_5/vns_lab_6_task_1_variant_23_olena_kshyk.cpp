#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char s[255];
    gets(s);

    int counter = 0;
    int min = 255;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != ' ')
            counter++;
        else
        {
            min = (min > counter) ? counter : min;
            counter = 0;
        }

    cout << min;

    return 0;
}