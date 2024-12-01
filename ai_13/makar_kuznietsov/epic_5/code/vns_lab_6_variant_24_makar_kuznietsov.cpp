#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 255
int countWords(char s[]);
int main()
{
    char buf[MAX];
    fgets(buf, MAX, stdin);
    std::cout << "number of words in string: " << countWords(buf);
}
int countWords(char s[])
{
    int count = 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    return count;
}
