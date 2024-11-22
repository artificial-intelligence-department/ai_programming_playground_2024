// variant 18
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Введіть дробове число " << endl;   // (1)
    double num;
    cin >> num;

    int hryvni = static_cast<int>(num);
    int copijky = static_cast<int>((num - hryvni) * 100 + 0.5);

    cout << num << " грн. - це " << hryvni << "грн." << copijky << "коп."<< endl;


    int KOL;    // (2)
    cout << "Введіть скільки шайб виробляє верстат-автомат за 1 годину" << endl;
    cin >> KOL;
    cout << "За 8 год верстат виробить " << KOL*8 << " шайб." << endl;
    cout << "За день (при 2-змінній роботі) виробить " << KOL*8*2 << " шайб." << endl;
    cout << "За 30-денний місяць, в якому 4 вихідних, і в \n кожній зміні верстат знаходиться 1 годину на \n профілактиці, і за день він працює 2 зміни, тож він виробить: ";
    cout << KOL*2*(8-1)*(30 - 4) << " шайб.";

    return 0;
}