#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Задача 1" << endl;
    double groshi;

    cout << "Введіть дробове число > ";
    cin >> groshi;

    int hryvna = static_cast<int>(groshi);
    int kopiyki = static_cast<int>((groshi - hryvna) * 100 + 0.5);

    if (kopiyki >= 100) {
        kopiyki -= 100;
        hryvna += 1;
    }

    cout <<  fixed <<  setprecision(2);
    cout << groshi << " грн. - це " << hryvna << " грн. " << kopiyki << " коп." << endl;

    cout << "Задача 2" << endl;
    int shaybHour = 100;
    int fullzmina = 8;
    int dwozmin = 2;
    int workDaysMonth = 30 - 4;
    int profilactika = 1;

    int shayb8Hour = shaybHour * fullzmina - profilactika;
    int fullday = shayb8Hour * dwozmin;
    int fullMonth = fullday * workDaysMonth;

    cout << "Шайб за 8-годинну зміну: " << shayb8Hour << endl;
    cout << "Шайб за робочий день: " << fullday << endl;
    cout << "Шайб за місяць: " << fullMonth << endl;

    return 0;
}
