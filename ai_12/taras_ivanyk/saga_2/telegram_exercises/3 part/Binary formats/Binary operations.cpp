#include <iostream>

int main() {
    unsigned int a = 29;  // 11101 
    unsigned int b = 15;  // 01111

    // AND
    unsigned int andResult = a & b;
    std::cout << "AND: " << andResult << std::endl;

    // OR
    unsigned int orResult = a | b;
    std::cout << "OR: " << orResult << std::endl;

    // XOR
    unsigned int xorResult = a ^ b;
    std::cout << "XOR: " << xorResult << std::endl;

    // Зсув бітів
    unsigned int shiftResult = a << 2;  
    std::cout << "Зсув вліво: " << shiftResult << std::endl;

    return 0;
}
