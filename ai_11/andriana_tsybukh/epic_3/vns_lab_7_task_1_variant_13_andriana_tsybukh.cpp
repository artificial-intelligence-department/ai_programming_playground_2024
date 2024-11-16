#include <iostream>
#include <cstdarg>    // для різної к-сті змінних toTernary
#include <string>
using namespace std;

// перетворення числа з десяткової в трійкову
string decimalToTernary(int number) {
    string ternary = "";
    if (number == 0) {
        return "0";
    }
    while (number > 0) {
        ternary = to_string(number % 3) + ternary;
        number /= 3;
    }
    return ternary;
}

// перетворення з десяткової в трійкову
void toTernary(int count, ...) {
    va_list args;
    va_start(args, count);
    cout << "Converting " << count << " numbers to ternary:" << endl;
    
    for (int i = 0; i < count; ++i) {
        int number = va_arg(args, int);
        string ternary = decimalToTernary(number);
        cout << "Decimal " << number << " -> Ternary " << ternary << endl;
    }
    
    va_end(args);
    cout << endl;
}

int main() {
    toTernary(3, 5, 10, 15);
    toTernary(4, 2, 8, 20, 25);
    toTernary(7, 1, 3, 6, 7, 9, 12, 18);

    return 0;
}
