#include <iostream>
#include <iomanip>
#include <cmath>

double count(int a, int b, int k){
    std::cout << std::setprecision(k);
    std::cout << a/(double)b;
    return a/(double)b;
}

int count(long long number, long long after){
    int count =0;
    long long a= number;
    long long b = after;
    while(b!=0){
        b/=10;
        count++;
    }
    b = after;
    a = a*pow(10,count);
    a += b;
    std::cout << a << "/" << pow(10,count);
    return 0;
}

int main(){
    count(9, 10, 6);
    std::cout << "\n";
    count(7, 678594008);
    return 0;
}

