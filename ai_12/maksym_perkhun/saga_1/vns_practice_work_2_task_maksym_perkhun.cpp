#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    double z, y;
    for(double x = -2.5; x <= 2; x += 0.5){
        z = abs(x) + pow(x, 2);
        y = z * (sin(pow((2 + x), 2)) / (2 + x));
        cout << setw(9) << "x = " << x << "\t" << "y = " << y << endl;
    }
    return 0; 
}