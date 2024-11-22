#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

int main() {
    char str[256];
    unordered_map<string, int> wordCount;

    cout << "Enter a string: ";

    gets(str);

    char* token = strtok(str, " ");
    while (token != NULL) {
        wordCount[token]++; 
        token = strtok(NULL, " ");
    }

    int maxCount = 0;
    char mostFrequentWord[256];
    for (const auto& el : wordCount) {
        if (el.second > maxCount) {
            maxCount = el.second;
            strcpy(mostFrequentWord, el.first.c_str());
        }
    }

    cout << "The word '" << mostFrequentWord << "' is the most frequent" << endl;

    return 0;
}
