#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double number;
    cout << "Перетворення числа в грошовий формат." << endl;
    cout << "Введіть дробове число > ";
    cin >> number;

    int first = floor(number);
    int second = round((number - first) * 100);
    cout << first << " грн. " << second << " коп. " << endl;

    int amount;
    int hours = 8 - 1;
    int days = 30 - 4;

    cout << "Введіть кількість шайб: ";
    cin >> amount;
    cout << "Кількість шайб за 8-и годинну зміну: " << amount * hours << endl;
    cout << "Кількість шайб за день: " << amount * 2 * hours << endl;
    cout << "Кількість шайб за місяць: " << amount * 2 * hours * days << endl;

    return 0;
}