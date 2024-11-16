#include <bits/stdc++.h>
#include<sstream>

using namespace std;

//Визначити яке слово зустрічається в рядку найчастіше.

int main() {
    char s[256];
    cout << "Введіть рядок : ";
    gets(s);

    // Видаляємо крапку в кінці, якщо вона є
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '.') {
        s[len - 1] = '\0';
    }


    stringstream ss(s);
    string word;
    map<string, int> word_count;

    while (ss >> word) {
        word_count[word]++;
    }

    vector<string> most_frequent_words;
    int max_count = 0;

    for (auto current: word_count)
        max_count = max(max_count, current.second);

    for (auto current: word_count) {
        if (current.second == max_count) {
            most_frequent_words.push_back(current.first);
        }
    }

    if (!most_frequent_words.empty()) {
        cout << "Найчастіше(ші) слово(а): { ";
        for (auto most_frequent_word: most_frequent_words) cout << "\"" << most_frequent_word << "\" ";
        cout << "} кількість повторів: " << max_count << endl;
    } else {
        cout << "Рядок порожній або не містить слів." << endl;
    }

    return 0;
}