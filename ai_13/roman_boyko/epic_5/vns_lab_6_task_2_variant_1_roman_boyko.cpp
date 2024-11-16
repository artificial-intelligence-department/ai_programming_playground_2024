#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
void words(char s[]);
int main()
{
    const int SIZE = 256;
    char s[SIZE];
    gets(s);
    words(s);
}
void words(char s[])
{
    char *token;
    token = strtok(s, " ");
    char *shortest = token;
    char *longest = token;
    while (token != nullptr)
    {
        if (strlen(shortest) > strlen(token))
        {
            shortest = token;
        }
        if (strlen(longest) < strlen(token))
        {
            longest = token;
        }
        token = strtok(nullptr, " ");
    }
    cout << "The longest word is: " << longest << endl;
    cout << "The shortest word is: " << shortest << endl;
}
