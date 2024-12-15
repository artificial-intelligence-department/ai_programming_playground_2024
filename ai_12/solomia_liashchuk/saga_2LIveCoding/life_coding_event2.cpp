#include <iostream>
#include <iomanip>  
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

bool IsPalindrom(int distance)
{
    string s = to_string(distance);
    string reversed_s = s;
    for(size_t i = 0; i < s.size() / 2; i++)
    {
        if(s[i] != s[s.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

double Convertation(double distance, const string measurementSystem)
{
    if(measurementSystem == "mi")
    {
        return distance * 1609.344;
    }
    else if(measurementSystem == "mi_US")
    {
        return distance * 1609.347;
    }
    else if(measurementSystem == "m")
    {
        return distance;
    }
    return 0;

}

int main()
{
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;

    double distance;
    cout << "Введіть відстань: ";
    cin >> distance;

    string  measurementSystem;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    double distanceValueMeters = Convertation(distance, measurementSystemv):
    if(distanceValueMeters == 0.0)
    {
        cout << "Error" << endl;
        continue;
    }

    double distanceKm = distanceValueMeters / 1000.0;
    if(IsPalindrom(static_cast<int>(distanceKm)))
    {
        distanceKm += 200.0;
    }


}
