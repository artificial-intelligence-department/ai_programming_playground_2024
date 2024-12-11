#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double z;
    double a = 2.4;
    for(double x = -3; x <= 3; x += 0.5){
    z = (pow(a, x) * log(abs(x+pow(2,3))))/(x+1);     
    cout << "z(" << x << ")" << " = " << z << endl;}
    return 0;
}