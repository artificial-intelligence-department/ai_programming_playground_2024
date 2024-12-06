#include <iostream>
#include <iomanip>
using namespace std;
   int main(){
cout << " Обчислення площі трикутника. \n";
cout << " Введіть початкові дані : \n ";

double side, height;
cout << " Підстава (см) > ";
cin >> side;
cout << "  Висота (см) > ";
cin >> height;
 
 double area = ( side * height ) / 2;
 cout << " Площа трикутника : " << area << " кв.см ";

cout << " РОзрахунок виробництва шайб : \n";
 int KOL;
 cout << " Введіть к-ть шайб, які виготовлє верстат за 1 годину :";
 cin >> KOL;
 
 int work_hours_1_shift = 8 - 1;
 int day_shift = 2;
 int w_days_in_month = 30 - 4;

 int p_shift = KOL * work_hours_1_shift;
 int p_day = p_shift * day_shift;
 int p_month = p_day * w_days_in_month;
  
cout << " Верстат виготовляє : \n";
cout<< " > За  одну зміну : " << p_shift << " шайб \n";
cout<< " > За один роб. день : " << p_day << " шайб \n";
cout<< " > За один роб. місяць : " << p_month << " шайб \n";
   
      return 0;
   }