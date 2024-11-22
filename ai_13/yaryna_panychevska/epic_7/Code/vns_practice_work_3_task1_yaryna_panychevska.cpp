#include <iostream>
using namespace std;
int main()
{
    int minutes;

    cout << "Enter minutes: ";
    cin >> minutes;
    string Hour;

    int total_hours = minutes / 60;
    int total_minutes = minutes % 60;
    if (total_hours > 1)
    {
        Hour = " hours";
    }
    else {
        Hour = " hour";
    }
    cout << minutes << " minutes is " << total_hours << Hour << " and " << total_minutes << " minutes.";
    return 0;
}