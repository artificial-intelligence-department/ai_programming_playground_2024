#include <iostream>
#include <cstdarg>

using namespace std;

int min(int count, ...) {
    va_list args;
    va_start(args, count);

    int minValue = va_arg(args, int);
    for (int i = 1; i < count; ++i) {
        int value = va_arg(args, int);
        if (value < minValue) {
            minValue = value;
        }
    }

    va_end(args);
    return minValue;
}

int main (){
    cout << "Мінімум серед (3, 7, 1, 9, 5): " << min(5, 3, 7, 1, 9, 5) << endl;
    cout << "Мінімум серед (15, 20, 3, 8, 7, 9, 5, 13, 11, 2): " << min(10, 15, 20, 3, 8, 7, 9, 5, 13, 11, 2) << endl;
    cout << "Мінімум серед (18, 25, 10, 7, 3, 21, 4, 9, 14, 8, 6, 2): " << min(12, 18, 25, 10, 7, 3, 21, 4, 9, 14, 8, 6, 2) << endl;
}