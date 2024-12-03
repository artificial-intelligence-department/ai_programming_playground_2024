#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

void sort_words(char s[]){
    vector<string> words;
    char* token = strtok(s, " ");
    while (token != NULL) {
        string word(token);

        if (!word.empty() && isalpha(word[0])) {
            words.push_back(word);
        }
        token = strtok(NULL, " ");
    }
    sort(words.begin(), words.end());
        cout << "Words that started with a letter:" << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }
}
int main() {
    cout << "Enter words: ";
    char s[256];
    gets(s); 
    sort_words(s);

    return 0;
}
