#include <iostream>
#include <cstdarg>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int lcmOfMany(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int result = va_arg(args, int);
    
    for (int i = 1; i < count; i++) {
        int next = va_arg(args, int);
        result = lcm(result, next);
    }
    
    va_end(args);
    return result;
}

int main() {
    cout << "НСК(3, 5, 6): " << lcmOfMany(3, 3, 5, 6) << endl;
    cout << "НСК(2, 3, 5, 6, 10): " << lcmOfMany(5, 2, 3, 5, 6, 10) << endl;
    cout << "НСК(1, 2, 3, 4, 5, 6): " << lcmOfMany(6, 1, 2, 3, 4, 5, 6) << endl;
}
