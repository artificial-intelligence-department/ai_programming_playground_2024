#include <iostream>
#include <cmath>
#include <stdarg.h>
#include <vector>

using namespace std;

int belong(int Radius, ...)
{

    vector<int> arr = {};

    va_list arg;
    va_start(arg, Radius);
    for (int i = 0; i < 11; i++)
    {
        arr.push_back(va_arg(arg, int));
    }

    for (int i = 0; i < 11; i++)
    {
        if (arr[i] < 1 || arr[i] > 100)
        {
            break;
        }
        if (pow(Radius, 2) == pow(arr[i], 2) + pow(arr[i + 1], 2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        i++;
    }
    va_end(arg);
    return 0;
};

int main()
{
    cout << "First" << endl;
    belong(5, 4, 3);
    cout << "Second" << endl;
    belong(10, 1, 3, 6, 8, 1, 3, 4, 5);
    cout << "Third" << endl;
    belong(10, 1, 2, 3, 4, 6, 8, 5, 7, 1, 10);
    return 0;
}