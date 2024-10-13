#include <iostream>

int main()
{
    short count = 0;
    long long arr[5];
    for (auto &el : arr)
    {
        std::cin >> el;
        if (el <= 0)
        {
            std::cout << "ERROR";
            return 0;
        }
        if (count != 0)
        {
            if (el > arr[count - 1])
            {
                std::cout << "LOSS";
                return 0;
            }
        }
        count++;
    }
    std::cout << "WIN";
    return 0;
}