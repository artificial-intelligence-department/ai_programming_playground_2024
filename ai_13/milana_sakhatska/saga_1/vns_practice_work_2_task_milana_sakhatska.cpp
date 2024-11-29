#include <iostream>
#include <cmath>
using namespace std;
const int NUM_POINTS = 5;
bool isInsideCircle(double x, double y, double a, double b, double R) {
    return pow(x - a, 2) + pow(y - b, 2) <= pow(R, 2);
}
int main() {
    double a, b, R;
    cout << "Enter the coordinates of the center (a, b): ";
    cin >> a >> b;
    cout << "Enter the radius R: ";
    cin >> R;

    double points[NUM_POINTS][2];
    cout << "Enter the coordinates of " << NUM_POINTS << " points (x, y):" << endl;

    for (int i = 0; i < NUM_POINTS; ++i) {
        cout << "Point " << i + 1 << ": ";
        cin >> points[i][0] >> points[i][1];
    }
    cout << "Points inside the circle:" << endl;
    int countInside = 0; 
    for (int i = 0; i < NUM_POINTS; ++i) {
        double* xPtr = &points[i][0];
        double* yPtr = &points[i][1];

        if (isInsideCircle(*xPtr, *yPtr, a, b, R)) {
            cout << "Point " << i + 1 << " (" << *xPtr << ", " << *yPtr << ") is inside the circle." << endl;
            ++countInside;
        } else {
            cout << "Point " << i + 1 << " (" << *xPtr << ", " << *yPtr << ") is outside the circle." << endl;
        }
    }
    cout << "Total points inside the circle: " << countInside << endl;
    return 0;
}
