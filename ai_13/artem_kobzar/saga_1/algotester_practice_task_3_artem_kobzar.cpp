#include <iostream>

int main() {
    unsigned int n, m;
    std::cin >> n >> m;
    if ((n * m) % 2 == 1) {
        std::cout << "Larry\n";
    } else {
        std::cout << "Sergei\n";
    }
    return 0;
}
