#include <iostream>
#include <cmath>
using namespace std;


void convertMinutesToHours() {
    int totalMinutes;
    cout << "Введіть часовий інтервал (у хвилинах): ";
    cin >> totalMinutes;

    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    cout << totalMinutes << " хвилин - це " << hours << " год. " << minutes << " хв." << endl;
}


void calculateTriangleArea() {
    double x1, y1, x2, y2, x3, y3;
    cout << "\nВведіть координати першої вершини (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Введіть координати другої вершини (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Введіть координати третьої вершини (x3, y3): ";
    cin >> x3 >> y3;

    double area = fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);

    cout << "Площа трикутника: " << area << endl;
}

int main() {
    cout << "Оберіть задачу:\n";
    cout << "1 - Перетворення хвилин у години та хвилини\n";
    cout << "2 - Обчислення площі трикутника за координатами\n";

    int choice;
    cout << "Ваш вибір: ";
    cin >> choice;

    if (choice == 1) {
        convertMinutesToHours();
    } else if (choice == 2) {
        calculateTriangleArea();
    } else {
        cout << "Некоректний вибір. Завершення програми." << endl;
    }

    return 0;
}

