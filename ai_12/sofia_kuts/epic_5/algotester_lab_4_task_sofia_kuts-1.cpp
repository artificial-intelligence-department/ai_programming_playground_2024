#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Видалення повторів
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    // Поворот на K
    std::rotate(a.begin(), a.begin() + (k % a.size()), a.end());

    // Виведення результату
    std::cout << a.size() << std::endl;
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
