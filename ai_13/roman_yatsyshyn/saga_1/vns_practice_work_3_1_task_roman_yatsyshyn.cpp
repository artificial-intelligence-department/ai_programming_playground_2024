#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x1, x2, x3, y1, y2, y3;
    cout << "Coordinates of the first vertex: ";
    cin >> x1 >> y1;
    cout << "Coordinates of the second vertex: ";
    cin >> x2 >> y2;
    cout << "Coordinates of the third vertex: ";
    cin >> x3 >> y3;

    double S = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    cout << "S = " << S << " кв. од." << endl;
}



