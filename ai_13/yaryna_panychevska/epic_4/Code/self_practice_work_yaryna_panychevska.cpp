#include <iostream>
using namespace std;

struct Advertising
{
    int Ad;
    double Click_Percentage;
    double Average_Earning;
};
void PrintInformation(Advertising information)
{
    cout << "Number of ads shown: " << information.Ad << endl;
    cout << "Percentage of visitors clicked on the ad: " << information.Click_Percentage << endl;
    cout << "Average earning per click: " << information.Average_Earning << endl;

    cout << "Total earning: " << (information.Ad * information.Click_Percentage / 100 * information.Average_Earning) << endl;
}
int main()
{
    Advertising ad;
    cout << "How many ads were shown today? : ";
    cin >> ad.Ad;
    cout << "What percentage of users clicked on the ads? : ";
    cin >> ad.Click_Percentage;
    cout << "What was the average earnings per click? $ : ";
    cin >> ad.Average_Earning;

    PrintInformation(ad);
    return 0;
}