#include <iostream>
#include <cstdarg>
using namespace std;

int sum(int n, ...);

int main() {
    cout << sum(5, 1, 2, 3, 4, 5) << endl;  
    cout << sum(15, 1, -2, 10, 4, 6, -2, 5, 6, -2, -9, 11, 4, 7, 12, -9) << endl;
    cout << sum(20, -1, 2, -3, 4, 7, 3, 8, -9, 2, 6, 4, 9 ,6, -5, 7, 1, 2, 4, -6, 9) << endl;
    return 0;
}

int sum(int n, ...) {
    va_list args;
    va_start(args, n);

    int next, total = 0, now = va_arg(args, int);  

    for (int i = 1; i < n; i++) {
        next = va_arg(args, int);  

        if (i % 2 == 1) total += now * next;
        else total -= now * next;  

        now = next;  
    }

    va_end(args);

    return total;
}

