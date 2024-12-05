#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int y; 
    cin >> y;

    bool isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));

    int januaryDays = 31;
    int februaryDays = isLeap ? 29 : 28;

    int dayOfYear = 47; 
    int day, month;

    if (dayOfYear <= januaryDays) {
        day = dayOfYear;
        month = 1;
    } else {
        day = dayOfYear - januaryDays;
        month = 2;
    }

    cout << setw(2) << setfill('0') << day << "."
         << setw(2) << setfill('0') << month << "." << y << endl;

    return 0;
}
