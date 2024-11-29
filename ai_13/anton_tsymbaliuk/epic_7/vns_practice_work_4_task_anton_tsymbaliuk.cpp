#include <iostream>

int main(){
    int number;
    std::cout << "Enter number : ";
    std::cin >> number;
    int sum = 0;
    int divider = 10;
    while(number % divider != number){
        sum += ((number % divider) / (divider / 10));
        divider *= 10;
    }
    sum += ((number % divider) / (divider / 10));
    std::cout << "Sum of numbers: " << sum << std::endl;

    return 0;
}