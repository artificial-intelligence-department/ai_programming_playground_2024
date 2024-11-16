#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

string Ternary(int number) {
    string ternary = "";
    if (number == 0) return "0";
    
    while (number > 0) {
        ternary = to_string(number % 3) + ternary;
        number /= 3;
    }
    return ternary;
}

void convertToTernary(int count, ...) {
    va_list args;
    va_start(args, count);
    
    cout << "Перетворення чисел у трійкову систему: ";
    
    for (int i = 0; i < count; i++) {
        int number = va_arg(args, int);
        cout << number << " -> " << Ternary(number) << "  ";
    }
    
    va_end(args);
    cout << endl;
}

int main() {
    convertToTernary(3, 1, 2, 3);
    convertToTernary(4, 4, 5, 6, 7);
    convertToTernary(7, 8, 9, 10, 11, 12, 13, 14);
    return 0;
}
