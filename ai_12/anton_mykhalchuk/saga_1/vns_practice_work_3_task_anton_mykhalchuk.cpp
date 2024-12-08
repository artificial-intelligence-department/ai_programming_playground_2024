#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int totalMinutes;
    cout << "Enter time interval (in minutes): ";
    cin >> totalMinutes;

    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    cout << totalMinutes << " minutes is " << hours << " h. " << minutes << " min." << endl;

    double x1, y1, x2, y2, x3, y3;

    cout << "Enter the coordinates of the first vertex (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the second vertex (x2, y2): ";
    cin >> x2 >> y2;

    cout << "Enter the coordinates of the third vertex (x3, y3): ";
    cin >> x3 >> y3;

    double area = abs(((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)) / 2.0);

    cout << "The area of the triangle is " << area << endl;

    return 0;
}