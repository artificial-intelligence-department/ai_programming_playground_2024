#include <iostream>
#include <cmath>

using namespace std;

double size(double x1, double x2, double y1, double y2){
    return sqrt( pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double square(double x1, double x2, double x3, double y1, double y2, double y3){
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

double squren(int points, double* coords){

    double x0 = coords[0];
    double y0 = coords[1];
    double area = 0;
    double x_prev = x0;
    double y_prev = y0;

    for (int i = 1; i < points; ++i)
    {
        double x = coords[i * 2];
        double y = coords[i * 2 + 1];
        area += (x_prev * y - y_prev * x);
        x_prev = x;
        y_prev = y;
    }
    
    area += (x_prev * y0 - y_prev * x0);

    return abs(area) / 2.0;
}

int main(){
    double x1, x2, x3, y1, y2, y3;
    int points;

    cout << "введіть координати 2 точок (x1, y1, x2, y2):" << endl;
    cin >> x1 >> y1 >> x2 >> y2;                                                                // відстань між двома точками
    cout << "довжина сторони: " << size(x1, x2, y1, y2) << endl;

    cout << "введіть координати 3 точок трикутника (x1, y1, x2, y2, x3, y3):" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;                                                   //трикутник                             
    cout << "Площа трикутника:" << square(x1, x2, x3, y1, y2, y3) << endl;

    
    do
    {
        cout << "Введіть кількість вершин багатокутника:" << endl;
    cin >> points;
        if (points < 3 )
    {
        cerr << "Недостатньо вершин" << endl;
    }
    } while (points < 3);
    
    double* coords = new double[points * 2];
    cout << "Введіть координати вершин по черзі (x, y): \n";
    for (int i = 0; i < points * 2; i++)
    {
        cin >> coords[i];
    }

    cout << "Площа багатокутника: " << squren(points, coords) << endl;

    return 0;
}