#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Приклад:
The event starts at 9:00 AM on November 15, 2024, and will last for 3 hours. Please arrive by 8:45 AM. Contact us at 555-123-4567 for any questions. The registration fee is $50 per person.
*/

/*
Перетворити рядок так, щоб всі букви в ньому були відсортовані за
зростанням.
*/

bool isLetter(char c) {
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return true;
    else return false;
}

void findLetters(char copy[]) {
    for(int i = 0; i < strlen(copy); i++) {
        if(!isLetter(copy[i]))
            copy[i] = 24;
    }
}

void sort(char* text) {
    for(int i = 0; i < strlen(text); i++) {
        if(text[i]==24) continue;
        for(int j = i + 1; j < strlen(text); j++) {
            if(text[j]==24) continue;
            if(text[j] < text[i])
                swap(text[i], text[j]);
        }
    }
}

void changeStr(char* original, char* copy) {
    for(int i = 0; i < strlen(original); i++) {
        if(copy[i]!=24) {
            original[i] = copy[i];
        }
    }
}

int main() {
    char text[256];
    gets(text); 
    char copy[256];
    strcpy(copy, text);
    findLetters(copy);
    sort(copy);
    changeStr(text, copy);
    cout << text;
    return 0;
}