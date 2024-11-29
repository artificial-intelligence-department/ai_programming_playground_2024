#include <iostream>
#include <cmath>
using namespace std;

void TransformMoney(float number, int &grn, int &cop) {
    grn = static_cast<int>(number); 
    cop = round((number - grn) * 100);
}

void Work(int washers_per_hour, int &work_shift, int &day, int &month) {
    const int hours_in_shift = 8;
    const int shifts_per_day = 2;
    const int days_in_month = 30;
    const int rest_days = 4;

    int effective_hours_per_shift = hours_in_shift - 1;
    work_shift = washers_per_hour * effective_hours_per_shift;
    day = work_shift * shifts_per_day; 
    month = day * (days_in_month - rest_days);
}

int main() {
    float number;
    int grn, cop, washers_per_hour;
    int work_shift, day, month;

    cout << "Введіть число для перетворення у грошовий формат: ";
    cin >> number;
    TransformMoney(number, grn, cop);
    cout << grn << " грн " << cop << " коп" << endl;

    cout << "Введіть кількість шайб, вироблених за годину:";
    cin >> washers_per_hour;
    Work(washers_per_hour, work_shift, day, month);
    cout << "Шайб вироблено за зміну: " << work_shift << endl;
    cout << "Шайб вироблено за день:  " << day << endl;
    cout << "Шайб вироблено за місяць: " << month << endl;

    return 0;
}
