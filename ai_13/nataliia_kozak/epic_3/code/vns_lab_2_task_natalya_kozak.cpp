#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float e = 0.0001, a;
    double sum = 0;
    int n = 2;
    a = n/pow(n-1, 2);
    while(a >= e){
        sum += a;
        n += 1;
        a = n/pow(n-1, 2);
    }
    cout << endl << sum;
    return 0;
}

