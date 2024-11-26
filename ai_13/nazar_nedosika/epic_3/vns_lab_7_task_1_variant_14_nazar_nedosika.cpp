#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binaryToDecimal(int binary) {
    int decimal = 0;
    int base = 1;
    
    while (binary) {
        int lastElement = binary % 10;
        binary /= 10;
        decimal += lastElement * base;
        base *= 2;
    }
    
    return decimal;
}

string decimalToTernary(int decimal) {
    string ternary = "";
    
    if (decimal == 0) {
        return "0";
    }
    
    while (decimal > 0) {
        ternary = to_string(decimal % 3) + ternary;
        decimal /= 3;
    }
    
    return ternary;
}

void binaryToTernary(const vector<int>& binaries) {
    for (int binary : binaries) {

        int decimal = binaryToDecimal(binary); 
        string ternary = decimalToTernary(decimal);

        cout << "Двійкове число: " << binary << " Трійкове число: " << ternary << endl;
    }
}

int main() {
    binaryToTernary({101, 110, 111}); 
    cout << "--------------------------" << endl;
    binaryToTernary({1010, 1100, 1110, 1001, 1111, 1000});
    cout << "--------------------------" << endl;
    binaryToTernary({10100, 11001, 11101, 10010, 10101, 11010, 11111});

    return 0;
}