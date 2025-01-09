#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double Mile_to_meter = 1609.344;

const double US_Mile_to_meter = 1609.347;

double convert_to_meters(double distance , const string& unit)
{
    if(unit == "Mile")
    {
        return distance *  Mile_to_meter;
    }

    if(unit == "Mile_US")
    {
        return distance *  US_Mile_to_meter;
    }

    if(unit == "Meter")
    {
        return distance;
    }

return 0;
}

bool IsPalindrome(int number)
{
    string str = to_string(number);
    return equal(str.begin() , str.begin() + str.size() / 2 , str.rbegin());

}

bool readPrice(const string& filename)
{
    ifstream file(filename);
    double price = 0; 
    if(file.is_open())
    {
        file >> price;
        file.close();
    } else {
        cout << "Не вдалось відкрити файл " << filename << endl;
    }
    return price;
}

double calculateCost(double distanceInMeters , const string& unit)
{
    string filename;
    
    if(unit == "Mile")
    {
        filename = "price_per_mile.txt";
    }

    if(unit == "Mile_US")
    {
        filename = "price_per_mile_us.txt";
    }

    if(unit == "Meter")
    {
       filename = "price_per_meter.txt";
    }

double pricePerMeter = readPrice(filename);
return  pricePerMeter + distanceInMeters;
}



int main() 
{
string userName , measurementSystem , collectedFile , convertBonus;
double distanceValue;

cout << "Введіть ваше ім'я: ";
cin >> userName;

 cout << "Введіть відстань: ";
 cin >> distanceValue;

  cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
  cin >> measurementSystem;

double distacneInMeters = convert_to_meters(distanceValue , measurementSystem);

return 0;

}