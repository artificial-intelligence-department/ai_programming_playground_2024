#include <iostream>
#include <cstdarg>
#include <cmath>
using namespace std;

int belong(unsigned rad, int argum, ...) {
    va_list args;
    va_start(args, argum);
    int isInside = 0;
    for (int i = 0; i < argum; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        if (sqrt(x*x + y*y) <= rad) {
            ++isInside;
        }  
    }
    va_end(args);
    return isInside;
}

int main() {
    unsigned rad;
    cout << "Radius: ";
    cin >> rad;
    cout << "amount of dots in circle(3 params): " << belong(rad, 1, 3, 5)
    << endl;
    cout << "amount of dots in circle(9 params): " << belong(rad, 4, 3, -6, 7, -2, 1, 3, 9, -2)
    << endl;
    cout << "amount of dots in circle(11 params): " << belong(rad, 5, 9, -8, 7, 1, -3, -4, 4, 6, 2, 10)
    << endl;
    return 0;
}