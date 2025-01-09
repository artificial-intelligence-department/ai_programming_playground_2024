#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float r, h;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter h: ";
    cin >> h;
    double S;
    S = 2 * M_PI * pow(r, 2) + 2 * M_PI * r * h; 
    cout << S;


    return 0;
}