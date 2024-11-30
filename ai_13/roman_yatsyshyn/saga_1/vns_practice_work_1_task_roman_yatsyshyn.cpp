#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double R, r, h;
    cin >> R >> r >> h;
    double l = sqrt(pow(h, 2.0) + (R - r));
    double S = M_PI*(R+r)*l + M_PI*pow(R, 2.0) + M_PI*pow(r, 2.0);
    double V = (M_PI/3) * (pow(R, 2.0) + pow(r, 2.0) + R*r) * h;
    cout << "l = " << l << ";\nS = " << S << ";\nV = " << V;
}

