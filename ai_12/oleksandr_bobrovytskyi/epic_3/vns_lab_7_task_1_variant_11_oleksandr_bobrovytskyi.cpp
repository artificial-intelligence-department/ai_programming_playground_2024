#include<iostream>
#include<cstdarg>

using namespace std;

void sum(int quantity, ...)
{
    va_list args;

    va_start(args, quantity);

    double ResultSum = 0.0;
    int Numerator = 0;
    int Denominator = 0;
    
    for(int i = 0; i < quantity; i++)
    {
        Numerator = va_arg(args, int);
        Denominator = va_arg(args, int);
        ResultSum += static_cast<double>(Numerator) / Denominator;
    }

    va_end(args);

    cout << "Сума дробів = " << ResultSum;
}

int main()
{
    sum(5, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6);
    cout << " (При 5 єлементах)" << endl;
    sum(10, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11);
    cout << " (При 10 єлементах)" << endl;
    sum(12, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13);
    cout << " (При 12 єлементах)" << endl;

    return 0;
}