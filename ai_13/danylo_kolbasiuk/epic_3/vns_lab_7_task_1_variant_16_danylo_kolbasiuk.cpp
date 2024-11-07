#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int daysfrombeginning(int day, int month, int year)
{
    int days=0;
    int daysinmonth[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < year; i++)
    {
        days+=365;
        if (i%4==0 && (i%100!=0 || i%400==0))
        {
            days++;
        }
    }
    for (int i=0; i<month-1; i++)
    {
        days+=daysinmonth[i];
        if (i==1 && (year%4==0  && (year%100!=0 || year%400==0)))
        {
            days++;
        }
    }
    days += day-1;
    return days;
}
void days(const vector<string> &result)
{
    vector<int> countyourdays;
    for(auto &date : result)
    {
        int day, month, year;
        stringstream stream(date);
        char dot;

        stream >> day >> dot >> month >> dot >> year;
        countyourdays.push_back(daysfrombeginning(day, month, year));
    }
    for(int i=0; i<countyourdays.size()-1; i++)
    {
        cout << countyourdays[i+1]-countyourdays[i] << endl;
    }
}
int main()
{
    days({"01.01.91", "01.02.92", "01.02.93"});
    days({"02.04.1596", "05.12.1600", "03.07.1602", "04.08.1605", "28.05.1607"});
    days({"08.01.2005", "14.02.2007", "25.03.2010", "29.04.2012", "28.05.2015", "21.07.2016", "27.11.2018", "06.12.2019"});
}