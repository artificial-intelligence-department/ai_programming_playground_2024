#include <iostream>
#include <cstdarg>

using namespace std;

int min(int count, ...)
{
    va_list args;
    va_start(args, count);

    int min_value = va_arg(args, int);

    for (int i = 1; i < count; ++i)
    {
        int value = va_arg(args, int);
        if (value < min_value)
        {
            min_value = value;
        }
    }

    va_end(args);
    return min_value;
}

int main()
{

    cout << "Minimum of 5: " << min(4, 9, -6, 88, 2) << endl;
    cout << "Minimum of 10: " << min(10, 7, -9, 4, 2, 77, 444, -2, 22, 0) << endl;
    cout << "Minimum of 12: " << min(12, 14, 44, 78, 1, 22, 37, 30, 567, 4, 89, 3) << endl;

    return 0;
}
