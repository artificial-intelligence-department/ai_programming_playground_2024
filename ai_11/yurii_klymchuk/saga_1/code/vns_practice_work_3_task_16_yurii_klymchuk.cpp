#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;

//вмкористав цілочисельну сталу, цілочисельні змінні
//ввід/вивід, дійсну змінну, математичні опеарації

const int days_in_year = 365;

int main () { 
    int vnesok, termin, vidsotok;

    cout << "Введіть початкові дані:\n";
    cout << "Величина внеску (грн.) > ";
    cin >> vnesok;
    cout << "Термін внеску (днів) > ";
    cin >> termin;
    cout << "Процентна ставка (річних в %) > ";
    cin >> vidsotok;

    float suma = (float)vnesok * pow((1 + (float)vidsotok/100), ((float)termin/(float)days_in_year));
    float dohid = suma - (float)vnesok;

    cout << "Дохід: " << fixed << setprecision(2) << dohid << " грн.";
    cout << "\nСума, після закінчення терміну внеску: " << setprecision(2) << suma << " грн.\n";
    //Обчислення об'єму порожнистого циліндра
    float r1, r2, h;
    cout << "---------------------------------------------------------------------------------\n";
    cout << "Обчислення об'єму порожнистого циліндра:\n";
    cout << "Діаметр циліндра > ";
    cin >> r1;
    cout << "Діаметр отвору > ";
    cin >> r2;
    cout << "Висота циліндра > ";
    cin >> h;

    float V = M_PI * h * (pow(r1, 2) - pow(r2, 2));
    cout << "Об'єм циліндра: " << fixed << setprecision(2) << V << " кв. од.";
    return 0;
}