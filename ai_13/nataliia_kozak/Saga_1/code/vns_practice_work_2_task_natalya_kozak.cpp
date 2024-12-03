#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double z;
    for(double x = 1; x <= 10; x += 2){
        for(double y = -4; y <= 3; y++){
            if(x > y){
                z = x*x/pow(x-5, 3);
            }
            else{
                z = pow(x-2, 3)/(y*pow(x-5, 4));
            }
            cout << endl << setprecision(10) << z;
        }
    }
    return 0;
}