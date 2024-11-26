#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float P = 3.1415;
    float y;
    for(float x = -5 ;x <= 5;x += 1){
        float P28 = pow(P,2)/8;
        float Pn4 = P/4;
        y = P28 - Pn4*abs(x);
        cout << "x: "<<x <<endl;
        cout << "y: "<<y <<endl <<endl;
    }
    return 0;
}
