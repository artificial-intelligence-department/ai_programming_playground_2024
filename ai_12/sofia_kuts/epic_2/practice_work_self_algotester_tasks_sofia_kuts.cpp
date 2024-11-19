#include <iostream>
#include <algorithm> // для std::max і std::min

int main() {
    long long h[4], d[4];

    // Зчитування довжин ніжок столу
    for (int i = 0; i < 4; ++i) {
        std::cin >> h[i];
    }

    // Зчитування довжин, які потрібно відрізати
    for (int i = 0; i < 4; ++i) {
        std::cin >> d[i];
    }

    // Перевірка на ERROR
    for (int i = 0; i < 4; ++i) {
        if (d[i] > h[i]) {
            std::cout << "ERROR" << std::endl;
            return 0;
        }
    }

    // Оновлення довжин ніжок після відрізання
    for (int i = 0; i < 4; ++i) {
        h[i] -= d[i];
    }

    // Перевірка на перевертання
    long long h_max = *std::max_element(h, h + 4);
    long long h_min = *std::min_element(h, h + 4);

    if (h_max >= 2 * h_min) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}