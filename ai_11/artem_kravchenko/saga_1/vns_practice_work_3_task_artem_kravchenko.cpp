#include <iostream>
#include <cmath>

using namespace std;

double area(double a, double b, double angle) {
    double pi = 3.14;
    double radian = angle * pi / 180;
    return 0.5 * a * b * sin(radian);
}

int main() {
    cout << "Завдання 1" << endl;
    double a, b, angle;
    cout << "Введіть дві сторони: " << endl;
    cin >> a >> b;
    cout << "Введіть кут між сторонами: " << endl;
    cin >> angle;

    double triangle_area = area(a, b, angle);
    cout << "Площа трикутника: " << triangle_area << endl;

    cout << "Завдання 2" << endl;
    double H, B, S;
    cout << "Введіть розмір ящика: " << endl;
    cin >> H >> B >> S;

    double bolt = 0.000002;
    double box = H * B * S;
    int result = static_cast<int>(box / bolt);

    cout << "Результат: " << result << endl;
    return 0;
}