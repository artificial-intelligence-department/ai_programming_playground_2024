#include <iostream>
#include <cstring>
#include <string.h>
#include <ctype.h>

using namespace std;

bool hasVovels (const char* word) {
    const char vovels[] = "euioaEUIOA";

    for (int i = 0; i < strlen(word); i++) {
        if (strchr(vovels, word[i])) {
            return true;
        } 
    }

    return false;
}





int main () {
    char str[256];
    char temp[256];
    char* token;

    cout << "Enter the text" << endl;

    // cin.getline(str, 256);
    fgets(str, 256, stdin);

    strcpy(temp, str);

    cout << "\n words without vovels: \n\n";

    token = strtok(temp, " .");

    while (token != NULL) {
        if (!hasVovels(token)) {
            cout << token << endl;
        }
        token = strtok(NULL, " .");
    }

    return 0;
}