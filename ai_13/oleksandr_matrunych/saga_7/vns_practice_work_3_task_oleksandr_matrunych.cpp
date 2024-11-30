#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double length, width, height;

    cout << "Calculation of the parallelepiped volume." << endl;
    cout << "Enter the initial data:" << endl;

    // Дані вводжу
    cout << "Length (cm) > ";
    cin >> length;
    cout << "Width (cm) > ";
    cin >> width;
    cout << "Height (cm) > ";
    cin >> height;

    double volume = length * width * height;

    cout << "Volume: " << fixed << setprecision(2) << volume << " cubic cm." << endl;

    // Фунти в кілограми
    double weightPounds;
    cout << "Enter the weight in pounds > ";
    cin >> weightPounds;

    double weightKg = weightPounds * 0.4059;

    cout << "Weight: " << fixed << setprecision(2) << weightKg << " kg." << endl;

    return 0;
}
