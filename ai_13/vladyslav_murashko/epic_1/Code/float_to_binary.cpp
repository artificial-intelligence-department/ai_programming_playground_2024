#include <iostream>


int main()
{
    union
    {
        float input;
        int   output;
    } data;

    std::cout << "Enter a number with floating point: ";
    std::cin >> data.input;

    const int numBits = sizeof(float) * CHAR_BIT;

    for (int i = numBits - 1; i >= 0; --i)
    {
        std::cout << ((data.output >> i) & 1);
    }

    std::cout << std::endl;

    return 0;
}