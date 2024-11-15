#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double length(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void belong(double triangle[][2], double x, double y)
{
    double ABC = area(triangle[0][0], triangle[0][1], triangle[1][0], triangle[1][1], triangle[2][0], triangle[2][1]);
    double ABM = area(triangle[0][0], triangle[0][1], triangle[1][0], triangle[1][1], x, y);
    double ACM = area(triangle[0][0], x, y, triangle[1][1], triangle[2][0], triangle[2][1]);
    double BCM = area(x, y, triangle[1][0], triangle[1][1], triangle[2][0], triangle[2][1]);
    if (ABC == 0)
    {
        cout << "This is not a triangle" << endl;
    }
    else if (ABC == ABM + ACM + BCM)
    {
        cout << "The dot is in the triangle" << endl;
    }
    else
    {
        cout << "The dot is not in the triangle" << endl;
    }
}
double angle(double x1, double y1, double x2, double y2)
{
    double a = (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
    return acos(a);
}

void isInsideConvexPolygon(double first_vx, double first_vy, double s, double vx1, double vy1, double x, double y, double a, double b)
{
    double vx2 = a - x, vy2 = b - y;
    double beta = angle(vx1, vy1, vx2, vy2);
    double gamma = angle(first_vx, first_vy, vx2, vy2);
    s += gamma + beta;
    s = int(s * 100);
    if (s == int(200 * M_PI))
    {
        cout << "The point is inside the polygon" << endl;
    }
    else
    {
        cout << "The point is outside the polygon" << endl;
    }
}

template <typename... points>
void isInsideConvexPolygon(double first_vx, double first_vy, double s, double vx1, double vy1, double x, double y, double a, double b, points... t)
{
    double vx2 = a - x, vy2 = b - y;
    double beta = angle(vx1, vy1, vx2, vy2);
    isInsideConvexPolygon(first_vx, first_vy, s + beta, vx2, vy2, x, y, t...);
}

template <typename... points>
void isInsideConvexPolygon(string start, double x, double y, double a, double b, points... t)
{
    double vx2 = a - x, vy2 = b - y;

    isInsideConvexPolygon(vx2, vy2, 0, vx2, vy2, x, y, t...);
}

int main()
{
    double l = length(6, 7, 3, 10);
    cout << "The distance between the points: " << l << endl;
    double triangle[3][2] = {{1,2}, {3,4}, {5,6}};
    belong(triangle, 9, 0);

    isInsideConvexPolygon("start", 5, 4, 2, 2, 5, 7, 9, 2);
    return 0;
}