#include <iostream>

int main()
{
    double resistance,voltage;
    std::cout << "Input the resistance and voltage of the electric circuit separated by a single space: ";
    std::cin >> resistance >> voltage;
    double power=voltage/resistance;
    std::cout << "Power of the electric circuit: " << power;
    return 0;
}