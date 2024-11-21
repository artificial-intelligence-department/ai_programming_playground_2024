#include <iostream>
int main()
{
    int a;
    std::cout << "enter number: ";
    std::cin >> a;
    int sum = 0;
    while (a != 0)
    {
        sum += a % 10;
        a /= 10;
    }
    std::cout << "the sum is: " << sum;
}
