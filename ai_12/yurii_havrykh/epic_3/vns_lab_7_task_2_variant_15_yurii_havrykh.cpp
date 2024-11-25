#include<bits/stdc++.h>
using namespace std;

void power(int a, int n){
    cout<<"int power "<<pow(a,n)<<endl;
}

void power(long long a, int n){
    cout<<"long long power "<<pow(a,n)<<endl;
}

void root(float a, int n){
    cout<<"float root "<<pow(a,1.0/n)<<endl;
}

void root(double a, int n){
    cout<<"double root "<<pow(a,1.0/n)<<endl;
}

int main(){
    int a=3;
    long long b=77;
    float c=96;
    double d=110;
    power(a,2);
    power(b,2);
    root(c,2);
    root(d,2);
}