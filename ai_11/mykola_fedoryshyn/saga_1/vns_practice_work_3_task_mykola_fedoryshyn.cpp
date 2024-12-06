#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int totalMinutes;
    
    cout << "Введіть часовий інтервал (в хвилинах) > ";
    cin >> totalMinutes;
    
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;
    
    cout << totalMinutes << " хвилин - це " << hours << " год. " << minutes << " хв." << endl;
//.............................................................................................
    double x1, y1, x2, y2, x3, y3;
    cout << "Введіть координати першої вершини (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Введіть координати другої вершини (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Введіть координати третьої вершини (x3, y3): ";
    cin >> x3 >> y3;

    double area = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    cout << "Площа трикутника: " << area << endl;


    return 0;
}
