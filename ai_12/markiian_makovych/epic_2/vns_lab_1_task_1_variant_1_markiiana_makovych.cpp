#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a = 1000;
    double b = 0.0001;
    double c, d, e, f, g;
    c = pow((a - b), 3);
    d = pow(a, 3);
    e = pow(b, 3);
    f = 3 * a * pow(b, 2);
    g = 3 * pow(a, 2) * b;

    cout << "Type double" << endl;
    cout << (c - d) / (e - f - g) << endl; // Виводить 1, бо це і є значення виразу

    float h = 1000;
    float m = 0.0001;
    float q, w, r, t, y;
    q = pow((h - m), 3);
    w = pow(h, 3);
    r = pow(m, 3);
    t = 3 * h * pow(m, 2);
    y = 3 * pow(h, 2) * m;

    cout << "Type float" << endl;

    cout << (q - w) / (r - t - y); // Виводить 1.28... , бо в типу даних float недостатньо місця щоб помістити певні числа

    return 0;
}