#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

void sort_digits_desc(string &word) {
    string digits;

    for (char ch : word) {
        if (isdigit(ch)) {
            digits += ch;
        }
    }

    sort(digits.begin(), digits.end(), greater<char>());

    size_t digit_index = 0;
    for (char &ch : word) {
        if (isdigit(ch)) {
            ch = digits[digit_index++];
        }
    }
}

int main() {
    string input;
    cout << "Введіть рядок: ";
    getline(cin, input);

    if (!input.empty() && input.back() == '.') {
        input.pop_back();
    }

    stringstream ss(input);
    string word, result;

    while (ss >> word) {
        sort_digits_desc(word);
        result += word + " ";
    }

    if (!result.empty()) {
        result.pop_back();
        result += ".";
    }

    cout << "Результат: " << result << endl;

    return 0;
}
