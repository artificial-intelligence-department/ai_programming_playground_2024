#include <iostream>

int main(){
    unsigned long int n;
    std::cin >> n;
    int k=0;
    while((n>=500)){
        k++;
        n-=500;
    }
    while((n>=200)){
        k++;
        n-=200;
    }
    while((n>=100)){
        k++;
        n-=100;
    }
    while((n>=50)){
        k++;
        n-=50;
    }
    while((n>=20)){
        k++;
        n-=20;
    }
    while((n>=10)){
        k++;
        n-=10;
    }
    while((n>=5)){
        k++;
        n-=5;
    }
    while((n>=2)){
        k++;
        n-=2;
    }
    while((n>=1)){
        k++;
        n-=1;
    }
    std::cout << k;
    return 0;
}