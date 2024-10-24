#include <iostream>
#include <stdarg.h>
using namespace std;
int sum(int k, ...);
int main()
{

    int s = sum(3, 1, 2, 7);
    cout << s;
}

int sum(int k, ...)
{
    va_list args;
    va_start(args, k);
    int s = 0;
    for (int i = 0; i < k; i++)
    {
        int x = va_arg(args, int);
        s += x;
    }
    va_end(args);
    return s;
}
