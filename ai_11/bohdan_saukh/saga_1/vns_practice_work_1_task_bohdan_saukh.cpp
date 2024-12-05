#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double R;
    double r;
    double h;
    
    cout << "Enter r: " << endl;
    cin >> r;
    cout << "Enter R: " << endl;
    cin >> R;
    cout << "Enter h: " << endl;
    cin >> h;

    double l = sqrt(h*h + (R - r)*(R - r));

    double S = M_PI*(R + r)*l + M_PI*R*R + M_PI*r*r;

    double V = (M_PI * h / 3.0) * (R*R + R*r + r*r);

    cout << "S: " << S << endl;
    cout << "V: " << V << endl;

    return 0;
}
