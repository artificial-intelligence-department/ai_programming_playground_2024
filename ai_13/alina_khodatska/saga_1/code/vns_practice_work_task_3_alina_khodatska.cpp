#include <iostream>
#include <cmath>  // For using the sin function

using namespace std;

int main() {
    double a, b, angle, area;

    cout << "Calculate the area of a triangle." << endl;

    cout << "Enter (by skipping) the length of the two sides (cm) of the triangle: ";
    cin >> a >> b;

    cout << "Enter the angle between the sides of the triangle (in degrees): ";
    cin >> angle;

    const double M_PI = 3.14159265358979323846;

    // Convert the angle from degrees to radians
    double angle_rad = angle * M_PI / 180.0;

    area = 0.5 * a * b * sin(angle_rad);

    cout << "Area of the triangle: " << area << " sq. cm." << endl;

    return 0;
}
