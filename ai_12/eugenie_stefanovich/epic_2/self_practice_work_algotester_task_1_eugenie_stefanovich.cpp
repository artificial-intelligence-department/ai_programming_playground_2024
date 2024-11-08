#include <iostream>

using namespace std;

int main()
{
    int n , kup;
    cin >> n;
    kup = 0;
    while(n>=500){
        kup += n / 500;
        n = n%500;}
    while(n>=200){
        kup += n / 200;
        n = n%200;}
    while(n>=100){
        kup += n / 100;
        n = n%100;}
    while(n>=50){
        kup += n / 50;
        n = n%50;}
    while(n>=20){
        kup += n / 20;
        n = n%20;}
    while(n>=10){
        kup += n / 10;
        n = n%10;}
    while(n>=5){
        kup += n / 5;
        n = n%5;}
    while(n>=2){
        kup += n / 2;
        n = n%2;}
    while(n>=1){
        kup++;
        n--;}
    cout << kup;
    
    return 0;
}
