#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    long long counter = 0;
    
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        if (num >= 2)
        {
            counter += num - 1;
        }    
    }
    std::cout << counter;
    return 0;
}


