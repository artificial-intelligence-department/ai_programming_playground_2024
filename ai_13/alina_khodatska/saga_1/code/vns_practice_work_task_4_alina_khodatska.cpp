#include <iostream>
#include <cmath>  // For using the M_PI constant and functions

using namespace std;

int main() {
    double radius, height, surface_area;

    cout << "Calculating the surface area of a cylinder." << endl;

    cout << "Enter the initial data:" << endl;
    cout << "Radius of the base (cm): ";
    cin >> radius;

    cout << "Height of the cylinder (cm): ";
    cin >> height;

    const double M_PI = 3.14159265358979323846;

    // Calculate the surface area of the cylinder using the formula
    surface_area = 2 * M_PI * radius * radius + 2 * M_PI * radius * height;

    cout << "Surface area of the cylinder: " << surface_area << " sq. cm." << endl;

    return 0;
}
