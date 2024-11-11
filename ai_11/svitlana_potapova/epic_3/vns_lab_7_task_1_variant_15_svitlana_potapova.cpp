#include <iostream>
#include <math.h>
#include <stdarg.h>
using namespace std;

void octalToDecimal(int numbersCount, ...)
{
    va_list args;
    va_start(args, numbersCount);

    cout << "Count is " << numbersCount << ": ";

    for (int i = 0; i < numbersCount; i++) {
        int octalNumber = va_arg(args, int);
        int decimalNumber = 0, j = 0, lastDigit;
    
        while (octalNumber !=0){
            lastDigit = octalNumber % 10;
            octalNumber /= 10;
            decimalNumber += lastDigit * pow(8, j);
            ++j;
        }
        cout << decimalNumber << " ";    
    }
    cout << endl;
    va_end(args);
};

int main(){
    octalToDecimal(3, 2, 7, 5);
    octalToDecimal(6, 12, 34, 75, 1, 4, 3);
    octalToDecimal(7, 1, 5, 7, 23, 41, 76, 102);
    
    return 0;
}

