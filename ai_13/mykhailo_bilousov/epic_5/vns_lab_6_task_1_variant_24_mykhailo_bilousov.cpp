#include <iostream>
#include <cstring>

int countwords(char str[])
{
    int count = 0;
    char* token = strtok(str, " ");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int main()
{
    char str[0x400];
    fgets(str, sizeof(str), stdin);
    std::cout << str << countwords(str) << std::endl;
}