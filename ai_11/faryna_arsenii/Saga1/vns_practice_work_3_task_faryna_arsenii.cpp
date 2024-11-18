#include <iostream>
#include <cmath> // для round

using namespace std;

int main (){
    cout << "--)-Money-(-----------------------------------------------------------------------------" << endl;
    double a;
    int money, cents;

    cout << "Enter a fractional number -> ";
    cin >> a;

    money = static_cast<int> (a);
    cents = round((a - money) * 100);

    if (cents == 100){
        money += 1;
        cents = 0;
    }

    cout << money << "грн. " << cents << " коп.";

    cout << "--)-Calculation_task-(-----------------------------------------------------------------------------" << endl;

    int KOL; // кількість шайб яку виготовить верстат за 1 годину
    cout << "Введіть кількість шайб яку виготовляє верстат за 1 годину: ";
    cin >> KOL;

    cout << "За 1 робочий день у дві зміни: " << KOL * 14 << endl; // кількість шайб за 1 робочий день в дві зміни
    cout << "За 30-ти денний місяць, враховуючи 4 вихідні: " << (KOL * 14) * 26 << endl; 

    return 0;
}
