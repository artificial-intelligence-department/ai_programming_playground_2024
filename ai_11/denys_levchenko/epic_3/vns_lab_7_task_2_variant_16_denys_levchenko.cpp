#include <iostream>
using namespace std;

int convert(int hours, int minutes) {
    return hours * 60 + minutes;
}

void convert(int totalMinutes, int &hours, int &minutes) {
    hours = totalMinutes / 60;
    minutes = totalMinutes % 60;
}

int main() {
    int hours, minutes, totalMinutes;

    cout << "Введіть кількість годин: ";
    cin >> hours;
    cout << "Введіть кількість хвилин: ";
    cin >> minutes;
    totalMinutes = convert(hours, minutes);
    cout << "Загальна кількість хвилин: " << totalMinutes << endl;

    cout << "\nВведіть загальну кількість хвилин: ";
    cin >> totalMinutes;
    convert(totalMinutes, hours, minutes);
    cout << "Години: " << hours << ", хвилини: " << minutes << endl;

    return 0;
}
