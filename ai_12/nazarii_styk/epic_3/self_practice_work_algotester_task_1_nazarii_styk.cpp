#include <iostream>

int main()
 {
    long long a, b, c;
    
    // Апельсини Марічки, Софійки і Петрика
    std::cin >> a >> b >> c;
    
    // Суми апельсинів Марічки та Софійки
    long long sum = a + b;
    
    if (sum > c) 
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}