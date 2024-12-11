#include <iostream>
#include <cmath>
using namespace std;
int main(){
    for ( int i = 0; i <= 10; i++) {
        int a = pow(2,i);
        cout << "2^" << i << " = " << a << endl;}
    return 0;
}