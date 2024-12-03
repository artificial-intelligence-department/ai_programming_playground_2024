#include <iostream>
#include <cmath>
using namespace std;

/*
Варіант 23
z = (cos(x) - 1) / (x+1), де x є [-3, 3]; h = 0,5; a = 2,4;
*/

int main() {
    float h = 0.5f;
    double z;
    for(float i = -3.0; i <= 3; i+=h) {
        if(i + 1 == 0) cout << "Denominator is 0!\n";
        else {
            z = (cos(i) - 1)/(i+1);
            cout << "For x = " << i << ", z = " << z << "\n";
        } 
    }   
    return 0;
}