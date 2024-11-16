#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    puts("Введіть строку: ");
    char s[256];
    gets(s);

    //remove the last "."
    int len = strlen(s);
    if(s[len-1] == '.') s[len-1] = '\0';

    //add words strating with a number to a vector using tockens
    vector<string> words;
    char* token = strtok(s, " ");

    while(token != nullptr){

        string word(token);

        if(isdigit(word[0])) words.push_back(word);

        token = strtok(nullptr, " ");
    }

    //sort them and cout
    sort(words.rbegin(), words.rend());

    cout << "Слова, що починаються з цифри, у спадному порядку:" << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }
}