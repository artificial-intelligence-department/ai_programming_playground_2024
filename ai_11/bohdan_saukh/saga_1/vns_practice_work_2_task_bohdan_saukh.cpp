#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b, R;
    cout << "Center(a, b): ";
    cin >> a >> b;
    cout << "R: ";
    cin >> R;


    double x[5];
    double y[5];
    
    cout << "Enter the coordinates of five points (x, y):" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Point " << i+1 << ": ";
        cin >> x[i] >> y[i];
    }

    cout << "Points that are in the circle:" << endl;
    for (int i = 0; i < 5; i++) {
        double distance = sqrt((x[i] - a) * (x[i] - a) + (y[i] - b) * (y[i] - b));
        if (distance <= R) {
            cout << "Point " << i + 1 << " (" << x[i] << ", " << y[i] << ")" << endl;
        }
    }

    return 0;
}