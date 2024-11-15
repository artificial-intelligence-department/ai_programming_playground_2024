#include <iostream>
#include <cstdarg>
using namespace std;

template<typename T>
T min(T argType, int count, ...) 
{
    va_list args; 
    va_start(args, count);
    T minValue = va_arg(args, T);

    for (int i = 1; i < count; i++)
    {
        T current = va_arg(args, T);
        if (current < minValue)
        {
            minValue = current;
        }
    }
    
    va_end(args);
    return minValue;
}



int main()
{
    cout << min(1, 5, 5, 3, -4, 6, 7) << endl;
    cout << min(1.1, 10, 2.1234, 5.23, 3, -4.3, -69.23, -4.4, 2, 9, -14.3, 7.56) << endl;
    cout << min(1, 12, 0, 1, -12, 5, 5, 3, -4, 6, 7, 99, -14, -45) << endl;

    return 0;
}