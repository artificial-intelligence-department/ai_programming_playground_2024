#include <iostream>
#include <cstdarg>

int sum(int n, int a, ...);

int main()
{
    std::cout << sum(5, 3, 100, 10, 90, 3) << std::endl;
    std::cout << sum(10, 8, 1, 1, 9, 69, 4, 10, 13, 3, 7) << std::endl;
    std::cout << sum(12, 5, 5, 50, 9, 6, 4, 70, 1, 6, 7, 3, 1) << std::endl;

    return 0;
}

int sum(int n, int a, ...)
{
    va_list args;
    va_start (args, a);
    int res = 0;
    int arr[n];

    arr[0] = a;
    for(int i = 1; i < n; i++)
        arr[i] = va_arg(args, int);

    va_end (args);

    for(int i = 0; i < n - 1; i ++)
    {
        if(i % 2)
            res -= arr[i] * arr[i+1];
        else
            res += arr[i] * arr[i + 1];
    }

    return res;
}