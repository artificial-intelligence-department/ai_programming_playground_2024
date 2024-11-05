#include <iostream>
#include <cstring>
#include <vector>

bool is_digit_only(const std::string &word) {
    for (char ch : word) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

bool is_alpha_only(const std::string &word) {
    for (char ch : word) {
        if (!isalpha(ch)) return false;
    }
    return true;
}

int main() {
    char s[256];
    std::cout << "Enter a string (max 255 characters): ";
    gets(s);

    std::vector<std::string> digits_only, letters_only, mixed;

    char *word = strtok(s, " ");
    while (word != nullptr) {
        std::string str_word = word;
        
        if (str_word.back() == '.') {
            str_word.pop_back();
        }

        if (is_digit_only(str_word)) {
            digits_only.push_back(str_word);
        } else if (is_alpha_only(str_word)) {
            letters_only.push_back(str_word);
        } else {
            mixed.push_back(str_word);
        }

        word = strtok(nullptr, " ");
    }

    std::cout << "Result: ";
    for (const auto &word : digits_only) std::cout << word << " ";
    for (const auto &word : letters_only) std::cout << word << " ";
    for (const auto &word : mixed) std::cout << word << " ";
    std::cout << "." << std::endl;

    return 0;
}
