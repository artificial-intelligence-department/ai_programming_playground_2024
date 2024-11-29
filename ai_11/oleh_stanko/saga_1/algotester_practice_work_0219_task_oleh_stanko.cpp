#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    int r, h;            
    double S, V;         

    cin >> r >> h;

    S = (4 * M_PI * pow(r, 2)) + (2 * M_PI * r * (h - 2 * r));

    V = ((4.0 / 3) * M_PI * pow(r, 3)) + (M_PI * pow(r, 2) * (h - 2 * r));

    cout << V << " ";
    cout << S;

    return 0;
}
