#include <iostream>
#include <cmath>
using namespace std;

double Area(double dX0, double dY0, double dX1, double dY1, double dX2, double dY2)
{
    double dArea = ((dX1 - dX0) * (dY2 - dY0) - (dX2 - dX0) * (dY1 - dY0)) / 2.0;
    if (dArea < 0.0)
    {
        return fabs(dArea);
    }
    return dArea;
}

int main()
{

    double x0, y0, x1, y1, x2, y2;

    cout << "Enter coordinates of the first point (x0 y0): " << endl;
    cout << "Example: 3 0" << endl;
    cin >> x0 >> y0;

    cout << "Enter coordinates of the second point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of the third point (x2 y2): ";
    cin >> x2 >> y2;

    double area = Area(x0, y0, x1, y1, x2, y2);

    cout << "The area of the triangle is: " << area << endl;

    return 0;
}
