#include <iostream>
#include <string>

int main() {
    long long x;
    std::cin >> x;

    std::string str_x = std::to_string(x);
    int lucky_count = 0;

    for (char digit : str_x) {
        if (digit == '4' || digit == '7') {
            lucky_count++;
        }
    }
    std::cout << lucky_count << std::endl;
    return 0;
}
