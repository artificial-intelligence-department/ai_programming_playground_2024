#include <iostream>
#include <stdarg.h>

using namespace std;

int sum(int count, ...)
{
    va_list args;
    va_start(args, count);
    
    int total = 0;
    bool multiply = true;
    int temp = 1;
    
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        
        if (multiply) {
            temp = num;
            multiply = false;
        } else {
            temp *= num;
            total += temp;
            multiply = true;
        }
    }
    
    va_end(args);
    return total;
}

int main() {
    cout << sum(8, 4, 5, 8, 9, 7, 15, 4, 2) << endl;
    cout << sum(10, 1, 3, 3, 4, 7, 8, 4, 12, 1, 2) << endl;
    cout << sum(12, 3, 16, 11, 3, 3, 4, 7, 8, 4, 12, 1, 2) << endl;
    return 0;
}