#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;

bool isIdentifier(string& word) {
    if (word.empty()) return false;
    if (!isalpha(word[0]) && word[0] != '_') return false;
    for (int i = 1; i < word.length(); i++) {
        if (!isalnum(word[i]) && word[i] != '_') return false;
    }
    const vector<std::string> keywords = {
        "int", "if", "else", "while", "for", "return", "class", "float", "double", "char", "bool"
    };
    for (const auto& keyword : keywords) {
        if (word == keyword) return false;
    }
    return true;
}

int main() {
    char s[256];
    cout << "Enter the text: ";
    gets(s);

    vector<string> identifiers;
    string word;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '.' || isspace(s[i])) {
            if (isIdentifier(word)) {
                identifiers.push_back(word);
            }
            word.clear();
        } else {
            word += s[i];
        }
    }
    string result;
    for (int j = 0; j < identifiers.size(); j++) {
        result += identifiers[j] + ' ';
    }
    cout << "Identifiers in the text: " << result;
    return 0;
}