#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a = 100;
    double b = 0.001;
    double c, d, e, f, g , l;
    c = pow((a - b), 4);
    d = pow(a, 4);
    e = 4*pow(a, 3)*b;
    l = 6*pow(a,2)*pow(b,2);
    f = pow(b, 4);
    g = 4 * pow(b, 3) * a;

    cout << "Type double" << endl;
    cout << (c - (d-e+l)) / (f - g) << endl; 

    float h = 100;
    float m = 0.001;
    float q, w, r, t, y , p;
    q = pow((h - m), 4);
    w = pow(h, 4);
    r = 4*pow(h, 3)*m;
    p = 6*pow(h,2)*pow(m,2);
    t = pow(m, 4);
    y = 4 * pow(m, 3) * h;

    cout << "Type float" << endl;

    cout << (q - (w - r + p)) / (t - y); 
    return 0;
}