#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, alpha, degrees;
    cout << "Two sides?" << endl;
    cin >> a >> b;
    cout << "Angle between?" << endl;
    cin >> alpha;

    degrees = alpha * (M_PI / 180.0);

    cout << (a * b * sin(degrees)) / 2 << endl;

    cout << endl;

    double H, B, S;
    double bolt = 0.000002;
    cout << "Write H,B,S:(in meters)" << endl;
    cin >> H >> B >> S;

    cout << "Ammount of bolts in box = " << (H * B * S) / bolt;

    return 0;
}