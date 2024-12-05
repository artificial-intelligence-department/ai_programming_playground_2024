#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string sortDigitsDescending(const string& word) {
    string result = word;
    vector<char> digits;

    for (char ch : result) {
        if (isdigit(ch)) {
            digits.push_back(ch);
        }
    }

    sort(digits.rbegin(), digits.rend());

    int digitIndex = 0;
    for (char& ch : result) {
        if (isdigit(ch)) {
            ch = digits[digitIndex++];
        }
    }

    return result;
}

string processString(const string& input) {
    string output;
    string word;

    for (char ch : input) {
        if (isspace(ch) || ch == '.') {
            if (!word.empty()) {
                output += sortDigitsDescending(word);
                word.clear();
            }
            output += ch;
        } else {
            word += ch;
        }
    }

    if (!word.empty()) {
        output += sortDigitsDescending(word);
    }

    return output;
}

int main() {
    const int MAX_LENGTH = 255;
    char input[MAX_LENGTH + 1];

    cout << "Введіть рядок (до 255 символів, закінчення на '.'): ";
    cin.getline(input, MAX_LENGTH);

    string processedString = processString(string(input));
    cout << "Оброблений рядок: " << processedString << endl;

    return 0;
}
