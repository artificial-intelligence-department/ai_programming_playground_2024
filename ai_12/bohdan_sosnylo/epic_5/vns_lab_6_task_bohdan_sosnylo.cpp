#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int funct(char str[], char str1[]) {
    char* pos = str;
    int i = 0;
    while ((pos = strstr(pos, str1)) != nullptr) {
        i++;
        pos += strlen(str1);
    }
    return i;
}

int main() {
    int i = 0;
    char str1[256];
    char str[256];

    cout << "Введіть рядок: ";
    gets(str);

    while (str[i] != ' ' && str[i] != '\0') {
        str1[i] = str[i];
        i++;
    }
    str1[i] = '\0'; 

    for (i = 0; i < funct(str, str1); i++) {
        cout << str1 << " ";
    }
    return 0;
}
