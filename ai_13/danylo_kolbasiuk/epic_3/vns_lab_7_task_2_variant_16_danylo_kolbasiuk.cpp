#include <iostream>
#include <cmath>

using namespace std;

void MintoHourandMin(int minute)
{
    int hour=floor(minute/60);
    int minute2=minute-hour*60;
    cout << hour << " hours, " << minute2 << " minutes.";
}
int HourandMintoMin(int hour, int minute)
{
    return hour*60+minute;
}
long HourandMintoMin(long hour, long minute)
{
    return hour*60+minute;
}
int main()
{
    int minutes1, minutes2, hours;
    long longmin, longhour;
    cout << "Enter the number of hours and minutes separated by a single space that you want to convert to minutes." << endl;
    cin >> hours >> minutes1;
    longmin=minutes1;
    longhour=hours;
    cout << HourandMintoMin(hours, minutes1) << " minutes." << endl;
    cout << HourandMintoMin(longhour, longmin) << endl;
    cout << "Now enter the number of minutes you want to convert into hours and minutes." << endl;
    cin >> minutes2;
    MintoHourandMin(minutes2);
}