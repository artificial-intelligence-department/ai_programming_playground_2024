#include <iostream>
#include <bitset>

int main() {
    int number = 12345;

    std::bitset<32> binary(number);
    std::cout << "Number in binary: " << binary << std::endl;

    return 0;
}
