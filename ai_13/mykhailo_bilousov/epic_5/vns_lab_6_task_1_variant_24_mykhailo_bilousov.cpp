#include <iostream>
#include <cstring>

int countwords(char str[])
{
    int count = 0;
    char* token = strtok(str, " .,?!\n");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " .,?!\n");
    }
    return count;
}

int main()
{
    char str[0x400];
    fgets(str, sizeof(str), stdin);
    std::cout << countwords(str) << std::endl;
}