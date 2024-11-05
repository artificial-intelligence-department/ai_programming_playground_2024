#include <iostream>
#include <cstdarg>
using namespace std;

int min(int numbers, ...) {
    int min_value = 2345345;
    va_list list;
    va_start(list, numbers);
    for(int i = 0; i < numbers; i++) {
        int value = va_arg(list, int);
        if(min_value > value)
            min_value = value;
    }
    va_end(list);
    return min_value;
}

int main() {
    cout << "Min of first 5 numbers: " << min(5, 123, 32, 0, -23, 12) << "\n";
    cout << "Min of second 10 numbers: " << min(10, 123, 32, 0, -23, 12, 8, 235, -23, -214, 1) << "\n";
    cout << "Min of third 12 numbers: " << min(12, 123, 32, 0, -23, 12, 8, 235, -23, -214, 1, -25234235, 1235421);
    return 0;
}