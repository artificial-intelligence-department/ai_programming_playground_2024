#include <iostream>

int main() {
    // Задаємо значення m і n
    int m, n;
    std::cout << "enter n: ";
    std::cin >> n;
    std::cout << "enter m: ";
    std::cin >> m;

    //обчислення
    int result1 = -(-m) - (++n);
    bool result2 = (m * n < n++);
    bool result3 = (n-- > m++);

    // Виведення результатів
    std::cout << "Result -m - ++n: " << result1 << std::endl;
    std::cout << "Result: m * n < n++: " << std::boolalpha << result2 << std::endl;
    std::cout << "Result: n-- > m++: " << std::boolalpha << result3 << std::endl;

    return 0;
}
