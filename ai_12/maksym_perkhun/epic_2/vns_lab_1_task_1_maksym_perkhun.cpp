#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float a = 1000, b = 0.0001, znam, chys, c, d, e, f, g;
    c = a - b;
    d = c * c;
    e = a * a;
    f = 2 * a * b;
    g = e - f;
    chys = d - g;
    znam = b * b;
    cout << chys / znam << endl;

    double aD = 1000, bD = 0.0001, znamD, chysD, cD, dD, eD, fD, gD;
    cD = aD - bD;
    dD = cD * cD;
    eD = aD * aD;
    fD = 2 * aD * bD;
    gD = eD - fD;
    chysD = dD - gD;
    znamD = bD* bD;
    cout << chysD / znamD << endl;
    return 0;
}