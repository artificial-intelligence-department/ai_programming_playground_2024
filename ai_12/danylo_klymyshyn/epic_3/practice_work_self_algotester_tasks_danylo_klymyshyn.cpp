#include<iostream>


int main(){

long n;
long counter = 1;
long temp;

long min;

std::cin >> n;

std::cin >> min;
for(int i = 1; i < n; ++i){
    std::cin >> temp;
    if(temp <= min){
        min = temp;
        ++counter;
    }
}

std::cout << counter;



    return 0;
}