#include <iostream>
#include <cmath>
using namespace std;

double calculateAngele(double a, double b, double c) //перевантажена функція
{
    return acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
}

void angles(int n, double sides[]) 
{
    for (int i = 0; i < n; i++) 
    {
        double a = sides[i];
        double b = sides[(i + 1) % n]; 
        double c = sides[(i + 2) % n]; 
        double angle = calculateAngele(a, b, c);
        cout << "Angle " << (i + 1) << ": " << angle << " degrees" << endl;
    }
}

int main() 
{
    double triangleSides[3] = {3.0, 4.0, 5.0};
    cout << "Angles of triangle:" << endl;
    angles(3, triangleSides);
    double polygon9Sides[9] = {3.0, 4.0, 5.0, 2.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    cout << "\nAngles of polygon (9 sides):" << endl;
    angles(9, polygon9Sides);

    double polygon11Sides[11] = {3.0, 4.0, 5.0, 2.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
    cout << "\nAngles of polygon (11 sides):" << endl;
    angles(11, polygon11Sides);

    return 0; 
}