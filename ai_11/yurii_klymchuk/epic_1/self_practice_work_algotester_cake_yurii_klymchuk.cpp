#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n,r;
    cin >> n;
    cin >> r;
    double r_large = M_PI*pow(r, 2);
    double r_small = sqrt(r_large/n/M_PI);
    cout << r_small; 
    return 0;
}