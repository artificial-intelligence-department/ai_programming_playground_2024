#include <iostream>
#include <stdio.h>
using namespace std;

int main () {

    int a;
    int b;
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;
    if ((a>=0 && a<=100) && (b>=0 && b<=100)) {
        cout<< "a+b=" << a+b;
    }   
    return 0;
}