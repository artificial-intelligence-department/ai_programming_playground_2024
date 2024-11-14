#include <iostream>
#include <cmath>
#include <cstdarg>
#define PI 3.14

using namespace std;

double Regular_Polygon(int numSides, double sideLength) {
    return (numSides * sideLength * sideLength) / (4 * tan(PI / numSides));
}

bool Sides_Equel(int numSides, va_list args) {
    double firstSide = va_arg(args, double);
    bool allEqual = true;

    for (int i = 1; i < numSides; ++i) {
        double side = va_arg(args, double);
        if (fabs(side - firstSide) > 0) {
            allEqual = false;
            break;
        }
    }

    return allEqual;
}

double square(int numSides, ...) {
    va_list args;
    va_start(args, numSides);

    if (numSides == 3) {
        double a = va_arg(args, double);
        double b = va_arg(args, double);
        double c = va_arg(args, double);
        va_end(args);

        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }


    bool isRegular = Sides_Equel(numSides, args);
    va_end(args);
    va_start(args, numSides);

    double area = 0;
    if (isRegular) {
        double firstSide = va_arg(args, double);
        area = Regular_Polygon(numSides, firstSide);
    }
    else {
        cout << "The polygon is not regular. You cannot calculate the area without more data.\n";
    }

    va_end(args);
    return area;
}

int main() {
    cout << "\n\nArea of the triangle: " << square(3, 3.0, 4.0, 5.0) << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "Area of the not regular polygon: " << square(5, 5.0, 2.0, 4.0, 9.0, 4.0) << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "Area of the regular polygon: " << square(8, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0) << endl;

    return 0;
}
