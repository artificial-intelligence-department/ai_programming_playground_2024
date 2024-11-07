#include <iostream>

long double sum(double n){
    if(n>0){
        return 1/((3*n-2)*(3*n-1))*sum(n-1) + sum(n-1);
    } else {
        return 1;
    }
}

int main(){
    double n;
    std::cin >> n;
    std::cout << sum(n);
    return 0;
}