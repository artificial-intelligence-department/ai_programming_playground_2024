#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float r, h;
    cout << endl;
    cin >> r >> h;
    cout << 2*M_PI*r*r+2*M_PI*r*h;

    float r1, r2, R;
    cout << endl;
    cin >> r1 >> r2;
    R = r1*r2 / (r1+r2);
    cout << R;
    return 0;
}