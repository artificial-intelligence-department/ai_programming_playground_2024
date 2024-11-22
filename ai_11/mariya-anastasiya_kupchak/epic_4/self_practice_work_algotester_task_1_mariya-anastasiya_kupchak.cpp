#include <iostream>

using namespace std;

struct Time 
{
    int hours;
    int minutes;
    int seconds;
};

int main() 
{
    struct Time time1, time2, result;

    cout << "Input the first time (hours minutes seconds): ";
    cin >> time1.hours >> time1.minutes >> time1.seconds;

    cout << "Input the second time (hours minutes seconds): ";
    cin >> time2.hours >> time2.minutes >> time2.seconds;

    result.seconds = time1.seconds + time2.seconds;
    result.minutes = time1.minutes + time2.minutes + (result.seconds / 60);
    result.hours = time1.hours + time2.hours + (result.minutes / 60);

    result.minutes %= 60;
    result.seconds %= 60;

    cout << "Resultant Time: " << endl << result.hours << ":" << result.minutes << ":" << result.seconds << endl;

    return 0;

}