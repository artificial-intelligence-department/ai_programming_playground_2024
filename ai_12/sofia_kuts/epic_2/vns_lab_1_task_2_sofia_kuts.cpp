#include <iostream>

int main() {
    int m , n;
    std::cout << "введіть значення m та n:";
    std::cin >> m >> n;

    int result1 = - -m - ++n;
    bool result2 = m * n < n++;
    bool result3 = n-- > m++;

    std::cout << "m-++n = " << result1 << std::endl;
    std::cout << "++m>--n = " << result2 << std::endl;
    std::cout << "--n<++m = " << result3 << std::endl;

    return 0;
}