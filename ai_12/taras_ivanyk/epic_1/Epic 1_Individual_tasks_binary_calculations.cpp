#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

string toBinary(int number, int bits) {
    string binary = "";
    for (int i = bits - 1; i >= 0; --i) {
        binary += (number & (1 << i)) ? '1' : '0';  
    }
    return binary;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    int x = rand() % 80 + 20;
    cout << "Generated number X: " << x << endl;

    string binaryX = toBinary(x, 7);  // 7 біт для чисел до 99
    cout << "X in binary system: " << binaryX << endl;

    int y = rand() % 80 + 20;
    cout << "Generated number Y: " << y << endl;

    string binaryY = toBinary(y, 7);
    cout << "Y in binary system: " << binaryY << endl;

    int sum = x + y;
    cout << "Sum X + Y = " << sum << " (" << toBinary(sum, 7) << " in binary system)" << endl;

    int subtraction = abs(x - y);
    cout << "Difference |X - Y| = " << subtraction << " (" << toBinary(subtraction, 7) << " in binary system)" << endl;

    if (x > y) {
        cout << "X / Y = " << static_cast<double>(x) / y << endl;
    } else {
        cout << "Y / X = " << static_cast<double>(y) / x << endl;
    }

    int product = x > y ? x * y : y * x;
    cout << "Product X * Y = " << product << " (" << toBinary(product, 14) << " in binary system)" << endl;

    int k = rand() % 80 + 20;
    cout << "Generated number K: " << k << endl;
    cout << "k in hexadecimal system: " << hex << k << endl;

    return 0;
}
