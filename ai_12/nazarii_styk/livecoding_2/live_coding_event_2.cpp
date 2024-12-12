#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void GenerateUderID(string& userName)
{
    // ToDo
}

float ConvertToMeters(float distanceValue, string measurementSystem)
{
    if(measurementSystem == "meter")
    {
        return distanceValue;
    }
    else if (measurementSystem == "mile")
    {
        return distanceValue / 1609.344; 
    }
    else if (measurementSystem == "mile_us")
    {
        return distanceValue / 1609.347; 
    }
    
}

int main()
{
    string userName, measurementSystem;
    float distanceValue;
    cout << "Введіть ваше ім'я: " << endl;
    cin >> userName;
    cout << "Введіть відстань: ";
    cin >> distanceValue; 
    while (measurementSystem != "meter" || measurementSystem != "mile" || measurementSystem != "mile_us")
    {
        cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
        cin >> measurementSystem;
    }
    ConvertToMeters(distanceValue, measurementSystem);
    cout << distanceValue << endl;
    

    return 0;
}

// measurementSystem != "meter" || measurementSystem != "mile" || measurementSystem != || "mile_us"