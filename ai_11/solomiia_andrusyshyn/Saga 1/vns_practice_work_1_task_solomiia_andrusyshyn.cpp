#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double R, r, h;
    cout << "Введіть радіус верхньої основи (r): ";
    cin >> r;
    cout << "Введіть радіус нижньої основи (R): ";
    cin >> R;
    cout << "Введіть висоту (h): ";
    cin >> h;

    double l = sqrt(h * h + (R - r) * (R - r));

    double S = M_PI * (R + r) * l + M_PI * R * R + M_PI * r * r;

    double V = (M_PI / 3) * (R * R + r * r + R * r) * h;

    cout << "Площа поверхні зрізаного конуса: " << S << endl;
    cout << "Об'єм зрізаного конуса: " << V << endl;

    return 0;
}
