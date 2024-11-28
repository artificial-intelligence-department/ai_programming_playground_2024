#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

void sortByDescending(string &word) {
    string numbers;
    for (char ch : word) {
        if (isdigit(ch)) {
            numbers += ch;
        }
    }

    sort(numbers.rbegin(), numbers.rend());

    auto it = numbers.begin();
    for (char &ch : word) {
        if (isdigit(ch) && it != numbers.end()) {
            ch = *it++;
        }
    }
}

int main() {
    string input;
    cout << "Введіть рядок (не більше 255 символів): ";
    getline(cin, input);

    if (!input.empty() && input.back() == '.') {
        input.pop_back();
    }

    stringstream ss(input);
    string word, result;

    while (ss >> word) {
        sortByDescending(word);
        result += word + " ";
    }

    if (!result.empty()) {
        result.pop_back();
        result += ".";
    }

    cout << "Результат: " << result << endl;

    return 0;
}
