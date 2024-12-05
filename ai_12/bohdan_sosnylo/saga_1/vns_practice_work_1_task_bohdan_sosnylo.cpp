#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double R, r, h, S, l, V;

    
    cout << "Введіть більшу основу: ";
    cin >> R;

    cout << "Введіть меншу основу: ";
    cin >> r;

    cout << "Введіть висоту: ";
    cin >> h;

    if (R <= 0 || r <= 0 || h <= 0 || R <= r) {
        cout << "неправильний ввід" << endl;
        return 1;
    }
    
    l = sqrt(pow(h, 2) + pow(R - r, 2)); 
    S = M_PI * (R + r) * l + M_PI * pow(R, 2) + M_PI * pow(r, 2); 
    V = M_PI / 3 * (pow(R, 2) + pow(r, 2) + R * r) * h; 

    cout << "Площа поверхні зрізаного конуса: " << S << endl;
    cout << "Об'єм зрізаного конуса: " << V << endl;

    return 0;
}
