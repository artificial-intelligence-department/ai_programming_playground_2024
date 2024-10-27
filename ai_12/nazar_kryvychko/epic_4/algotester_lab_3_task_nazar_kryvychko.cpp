#include <iostream>
#include <string>

std::string compress_string(const std::string& s) {
    std::string compressed;
    int count = 1;

    for (size_t i = 1; i <= s.size(); ++i) {
        if (i < s.size() && s[i] == s[i - 1]) {
            ++count;
        } else {
            compressed.push_back(s[i - 1]);
            if (count > 1) {
                compressed += std::to_string(count);
            }
            count = 1;
        }
    }

    return compressed;
}

int main() {
    std::string s;
    std::cin >> s;

    std::string compressed = compress_string(s);
    std::cout << compressed << std::endl;

    return 0;
}

