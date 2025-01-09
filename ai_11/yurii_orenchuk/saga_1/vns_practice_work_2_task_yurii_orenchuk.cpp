#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double hx = 0.5, ha = 1;
    double y = 0;

    for(double x = 1; x < 8.5; x+=hx){
        for(double a = 2; a < 11; a+=ha){
            if(a > x){
                y = pow(a, 2) + x;
                cout << "x: " << x << " a: " << a << " y: " << y << endl;
            }
            else if(a == x){
                y = pow(a, 2);
                cout << "x: " << x << " a: " << a << " y: " << y << endl;
            }
            else if(a < x){
                y = pow(a, 2) - x;
                cout << "x: " << x << " a: " << a << " y: " << y << endl;
            }
        }
    }

    return 0;
}