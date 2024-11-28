#include <iostream>

double factorial(int n)
{
    if (n<1)
    {
        return 1;
    }
    else 
    {
        return factorial(n-1)*n;
    }
}

int main()
{
    int n;
    input:
    std::cout << "Input a whole number: ";
    std::cin >> n;
    if(n<0)
    {
        std::cout << "The number is less than zero, try again." << std::endl;
        goto input;
    }
    std::cout << "The factorial of " << n << " equals " << factorial(n) << ".";
    return 0;
}