#include <iostream>
using namespace std;

int main() {
    double dist;
    double time;
    double coef = 0.06;
    cout << "Enter the distance: ";
    cin >> dist;
    cout << "Enter the time: ";
    cin >> time;
    cout << "The velocity is " << dist*coef /  time << "km/hr" << endl;

    double voltage, amperage;
    cin >> voltage >> amperage;
    cout << "The resistance is " << voltage/amperage << " Om";

    return 0;
}