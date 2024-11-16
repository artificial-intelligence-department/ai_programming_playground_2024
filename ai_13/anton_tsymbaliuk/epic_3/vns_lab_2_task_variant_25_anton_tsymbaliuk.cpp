#include <iostream>
#include <math.h>

int main(){
    double sum = 0;
    for(int i = 1; i <= 7; i++){
        sum += double(i*i) * exp(-sqrt(i));
    }
    std::cout << "Sum of first 7 elements of sequence: " << sum;    
    return 0;
}