#include <iostream>
#include <cmath> 

int main() {
    int m = 5, n = 3;

    // 1) m + --n
    int result1 = m + --n;
    std::cout << "Result of m + --n: " << result1 << " (m=" << m << ", n=" << n << ")" << std::endl;

    m = 5;
    n = 3;

    // 2) m++ < ++n
    bool result2 = m++ < ++n;
    std::cout << "Result of m++ < ++n: " << (result2 ? "true" : "false") << " (m=" << m << ", n=" << n << ")" << std::endl;

    m = 5;
    n = 3;

    // 3) n-- < --m
    bool result3 = n-- < --m;
    std::cout << "Result of n-- < --m: " << (result3 ? "true" : "false") << " (m=" << m << ", n=" << n << ")" << std::endl;

    //Пояснення:
    //1) Вираз'm + --n'спочатку скорочує'n', а потім додає його до'm'.
    //2) Вираз'm++ < + + n'спочатку збільшує'n', а потім порівнює з поточним'm', а потім збільшує'm'.
    //3) Вираз'n-- < -m'зменшує'm', а потім порівнює з поточним'n', а потім зменшує'n'.

    return 0;
}
