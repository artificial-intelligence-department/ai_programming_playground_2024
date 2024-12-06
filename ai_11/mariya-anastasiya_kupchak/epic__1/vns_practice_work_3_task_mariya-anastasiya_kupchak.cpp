// Variant 19

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    cout << "Обчислення площі трикутника." << endl;
    cout << "Введіть координати кутів" << endl << "(числа розділяйте пропуском):" << endl;

    double x1, y1, x2, y2, x3, y3;

    cout << "x1, y1 > ";
    cin >> x1 >> y1;
    cout << "x2, y2 > ";
    cin >> x2 >> y2;
    cout << "x3, y3 > ";
    cin >> x3 >> y3;

    double area;
    double a, b, c, p;

    a = pow((pow((x2 - x1), 2) + pow((y2 - y1), 2)), 0.5);   
    b = pow((pow((x3 - x2), 2) + pow((y3 - y2), 2)), 0.5);
    c = pow((pow((x1 - x3), 2) + pow((y1 - y3), 2)), 0.5);
    p = (a + b + c) / 2;
    area = pow((p * (p - a) * (p - b) * (p - c)), 0.5);

    cout << "Площа трикутника: " << area << " кв.см." << endl << endl;

    cout << "Обчислення вартості покупки." << endl;

    int notebooks, pencils;
    double price_n, price_p;

    cout << "Кількість зошитів: ";
    cin >> notebooks;
    cout << endl << "Ціна одного зошита: ";
    cin >> price_n;
    cout << endl << "Кількість олівців: ";
    cin >> pencils;
    cout << endl << "Ціна одного олівця: ";
    cin >> price_p;

    double cost = (notebooks * price_n) + (pencils * price_p);

    cout << "Загальна вартість покупки: " << cost << " грн." << endl;

    return 0;
}
