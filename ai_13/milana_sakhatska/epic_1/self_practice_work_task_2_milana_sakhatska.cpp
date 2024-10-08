#include <iostream> 

int main() {
    int a, b;  

    std::cout << "Введіть a: ";
    std::cin >> a;

    std::cout << "Введіть b: ";
    std::cin >> b;

    int sum = a + b;

    std::cout << "Сума чисел " << a << " і " << b << " дорівнює: " << sum << std::endl;

    return 0;  
}
