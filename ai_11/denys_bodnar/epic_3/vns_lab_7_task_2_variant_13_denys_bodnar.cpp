#include <iostream>
#include <cmath>

using namespace std;

void drib10(double decimal) {
    int precision = 1000000;  //висока точність для перетворення
    int znam = precision;
    int chyseln = round(decimal * precision);

    int nsd = 1;
    for (int i = 1; i <= chyseln && i <= znam; i++) {
        if (chyseln % i == 0 && znam % i == 0) {
            nsd = i;
        }
    }

    chyseln /= nsd;
    znam /= nsd;

    cout << "Звичайний дріб: " << chyseln << "/" << znam << endl;
}

double prostdribv10(int chyseln, int znam, int precision = 1) {
    double result = static_cast<double>(chyseln) / znam;
    return round(result * precision) / precision;
}

int main() {
    double decimal = 0.77;
    cout << "Десятковий дріб у звичайний: ";
    drib10(decimal);

    cout << "Звичайний дріб у десятковий: ";
    cout << prostdribv10(6, 7) << endl;

    cout << "Звичайний дріб у десятковий з точною точністю: ";
    cout << prostdribv10(1, 2, 3000) << endl;

    return 0;
}
