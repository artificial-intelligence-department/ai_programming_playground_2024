#include <iostream>

int main() {
    long long arr[5];
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];

        if (arr[i] <= 0) {
            std::cout << "ERROR";
            return 0;
        }

        if (i > 0 && arr[i] > arr[i - 1]) {
            std::cout << "LOSS";
            return 0;
        }
    }
    std::cout << "WIN";
    return 0;
}


