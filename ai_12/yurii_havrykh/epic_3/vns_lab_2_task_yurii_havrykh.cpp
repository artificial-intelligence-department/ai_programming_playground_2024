#include<bits/stdc++.h>
using namespace std;

int main(){
    double epsilon=0.0001;
    double result=0;
    int n=1;
    double a=1;
    int factorial=1;
    while(a>epsilon){
        a= pow(factorial,2) / (pow(2,n*n));
        result+=a;
        n++;
        factorial*=n;
    }
    printf("Sum= %.8lf",result);
}