#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;

bool circle_check(double x, double y, double R) {
    return (x * x + y * y) <= (R * R);
}

int belong(double R, int numPoints, ...) {
    int count = 0;
    va_list args;
    va_start(args, numPoints);

    for (int i = 0; i < numPoints; ++i) {
        double x = va_arg(args, double);
        double y = va_arg(args, double);
        if (circle_check(x, y, R)) {
            count++;
        }
    }

    va_end(args);
    return count;
}

int main() {
    double radius;
    cout << "Введіть радіус круга: ";
    cin >> radius;

    cout << "Введіть координати точки (х, у) для перевірки (1 точка): ";
    double x1, y1;
    cin >> x1 >> y1;
    cout << "Точки, що належать кругу (3 параметри): " << belong(radius, 1, x1, y1) << endl;

    cout << "Введіть координати для 4 точок (х1, у1, х2, у2, х3, у3, х4, у4): ";
    double x2, y2, x3, y3, x4, y4, x5, y5;
    cin >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;
    cout << "Точки, що належать кругу (9 параметрів): " << belong(radius, 4, x2, y2, x3, y3, x4, y4, x5, y5) << endl;

    cout << "Введіть координати для 5 точок (х1, у1, х2, у2, х3, у3, х4, у4, х5, у5): ";
    double x6, y6, x7, y7, x8, y8, x9, y9, x10, y10;
    cin >> x6 >> y6 >> x7 >> y7 >> x8 >> y8 >> x9 >> y9 >> x10 >> y10;
    cout << "Точки, що належать кругу (11 параметрів): " << belong(radius, 5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10) << endl;

    return 0;
}