#include <iostream>
#include <math.h>
using namespace std;

int power(int base, int n){
    return pow(base, n);
}

double power(double base, int n){
    return pow(base, 1.0/n);
}

int main(){
    cout << "Raising to power: " << power(3,4) << endl;
    cout << "Root: " << power(2.25, 2) << endl;

    return 0;
}
