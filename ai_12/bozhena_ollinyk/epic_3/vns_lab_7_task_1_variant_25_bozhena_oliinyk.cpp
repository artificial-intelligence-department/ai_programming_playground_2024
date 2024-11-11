#include <iostream>
#include <cmath>

using namespace std;

double side2D(float x1, float y1, float x2, float y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double side3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}

double square2D(float x1, float y1, float x2, float y2, float x3, float y3)
{
    double ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    double ca = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
    double p = (ab + bc + ca) / 2;

    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

double square3D(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
    double ux = x2 - x1;
    double uy = y2 - y1;
    double uz = z2 - z1;

    double vx = x3 - x1;
    double vy = y3 - y1;
    double vz = z3 - z1;

    double cross_x = uy * vz - uz * vy;
    double cross_y = uz * vx - ux * vz;
    double cross_z = ux * vy - uy * vx;

    double area = 0.5 * sqrt(pow(cross_x, 2) + pow(cross_y, 2) + pow(cross_z, 2));
    return area;
}

double square1(bool is3D, int n, double *x, double *y, double *z = nullptr)
{
    double maxDiag = 0;
    int index1 = 0, index2 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (i == 0 && j == n - 1)
                continue;
            double diag;
            if (is3D)
            {
                diag = side3D(x[i], y[i], z[i], x[j], y[j], z[j]);
            }
            else
            {
                diag = side2D(x[i], y[i], x[j], y[j]);
            }
            if (diag > maxDiag)
            {
                maxDiag = diag;
                index1 = i;
                index2 = j;
            }
        }
    }

    int prevIndex = (index1 - 1 + n) % n;

    double area;
    if (is3D)
    {
        area = square3D(x[prevIndex], y[prevIndex], z[prevIndex], x[index1], y[index1], z[index1], x[index2], y[index2], z[index2]);
    }
    else
    {
        area = square2D(x[prevIndex], y[prevIndex], x[index1], y[index1], x[index2], y[index2]);
    }

    return area;
}

int main()
{

    float ax, ay, az;
    cout << "Введіть координати точки A (x, y): ";
    cin >> ax >> ay;

    cout << "Введіть координату A z (0, якщо 2D): ";
    cin >> az;

    bool is3D = false;
    if( az !=0 ){
        is3D = true;
    }

    float bx, by, bz = 0;
    cout << "Введіть координати точки B (x, y): ";
    cin >> bx >> by;
    if (is3D)
    {
        cout << "Введіть координату B z: ";
        cin >> bz;
    }

    float cx, cy, cz = 0;
    cout << "Введіть координати точки C (x, y): ";
    cin >> cx >> cy;
    if (is3D)
    {
        cout << "Введіть координату C z: ";
        cin >> cz;
    }

    if (is3D)
    {
        cout << "AB = " << side3D(ax, ay, az, bx, by, bz) << endl;
        cout << "BC = " << side3D(bx, by, bz, cx, cy, cz) << endl;
        cout << "CA = " << side3D(cx, cy, cz, ax, ay, az) << endl;
    }
    else
    {
        cout << "AB = " << side2D(ax, ay, bx, by) << endl;
        cout << "BC = " << side2D(bx, by, cx, cy) << endl;
        cout << "CA = " << side2D(cx, cy, ax, ay) << endl;
    }

    if (is3D)
    {
        cout << "Area of ABC = " << square3D(ax, ay, az, bx, by, bz, cx, cy, cz) << endl;
    }
    else
    {
        cout << "Area of ABC = " << square2D(ax, ay, bx, by, cx, cy) << endl;
    }

    int n;
    cout << "Input how many vertexes does the shape have: ";
    cin >> n;

    double x [n];
    double y [n]; 
    double z [n]; 

    x[0] = ax;
    y[0] = ay;
    z[0] = is3D ? az : 0;
    x[1] = bx;
    y[1] = by;
    z[1] = is3D ? bz : 0;
    x[2] = cx;
    y[2] = cy;
    z[2] = is3D ? cz : 0;

    for (int i = 3; i < n; i++)
    {
        cout << "Enter coordinates for vertex " << i + 1 << " (x, y" << (is3D ? ", z" : "") << "): ";
        cin >> x[i] >> y[i];
        if (is3D)
        {
            cin >> z[i];
        }
        else
        {
            z[i] = 0;
        }
    }

    if (is3D)
    {
        cout << "Area of ABC placed on the biggest diagonal of n-shape = " << square1(is3D, n, x, y, z);
    }
    else
    {
        cout << "Area of ABC placed on the biggest diagonal of n-shape = " << square1(is3D, n, x, y, nullptr);
    }

    return 0;
}