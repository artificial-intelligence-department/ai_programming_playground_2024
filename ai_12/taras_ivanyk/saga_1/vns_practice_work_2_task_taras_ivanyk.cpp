// variant 23
#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    double z,x;
    double Hx = 0.5;

    for(double x = -3; x <= 3; x += Hx){
        if(x == -1){
            cout << "Error ";   //
        } else{
        z = (cos(x) - 1) / (x + 1);
        cout << z << ", ";
        }
    }
    return 0;
}