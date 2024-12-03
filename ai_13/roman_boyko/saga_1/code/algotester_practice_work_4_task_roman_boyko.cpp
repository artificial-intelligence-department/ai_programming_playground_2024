#include <iostream>
using namespace std;

int main()
{
    string weekd[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string d;
    cin >> d;
    int n;
    cin >> n;
    int today = 0;
    for (int i = 0; i < 7; i++)
    {
        if (weekd[i] == d)
        {
            today = i;
            break;
        }
    }

    int countDays[7] = {0, 0, 0, 0, 0, 0, 0};
    int povnyh = n / 7;
    int nep = n % 7;
    for (int i = 0; i < 7; i++)
    {
        countDays[i] = povnyh;
    }
    for (int i = 0; i < nep; i++)
    {
        countDays[(today + i) % 7]++;
    }
    for (int i = 0; i < 7; i++)
    {
        cout << countDays[i] << " ";
    }
}