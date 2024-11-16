#include <iostream>
#include <string>
#include <cmath>
#include <cstdarg> 
using namespace std;

string binaryToTernary(int binary) {
    int decimal = 0;
    int power = 0;

    while (binary > 0) {
        int last_digit = binary % 10;
        decimal += last_digit * pow(2, power);
        binary /= 10;
        power++;
    }

    string ternary = "";
    while (decimal > 0) {
        int remainder = decimal % 3;
        ternary = to_string(remainder) + ternary;
        decimal /= 3;
    }

    if (ternary == "") {
        return "0";
    }

    return ternary;
}


void Convert(int count, ...) {
    va_list args; 
    va_start(args, count); 

    
    for (int i = 0; i < count; i++) {
        int binary = va_arg(args, int);
        string ternary = binaryToTernary(binary); 
        cout << "Binary: " << binary << " -> Ternary: " << ternary << endl;
        if(i+1 == count){
            cout << "End of function with " << count << " arguments\n\n";
        }
    }

    va_end(args); 
}

int main() {
    Convert(3, 101, 110, 10110);
    Convert(6, 1001, 1010, 1101, 1111, 10000, 10001); 
    Convert(7, 10101, 11011, 11101, 100111, 101010, 110110, 111111); 

    return 0;
}
