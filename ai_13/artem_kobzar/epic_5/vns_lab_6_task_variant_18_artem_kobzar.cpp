#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    cout << "Enter string: ";
    char s[256];
    cin.getline(s, 256);

    int len = strlen(s);
    if (len > 0 && s[len - 1] == '.') {
        s[len - 1] = '\0';
    }

    vector<string> words;
    char* token = strtok(s, " ");

    while (token != nullptr) {
        string word(token);

        if (!word.empty() && isdigit(word[0])) {
            words.push_back(word);
        }

        token = strtok(nullptr, " ");
    }

    sort(words.rbegin(), words.rend());

    cout << "Words that started with nums:" << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}
