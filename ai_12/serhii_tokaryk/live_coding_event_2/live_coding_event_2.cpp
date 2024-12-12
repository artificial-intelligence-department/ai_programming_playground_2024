#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double Mile_to_meter = 1609.344;

const double US_Mile_to_meter = 1609.344;

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
    return 
}

int main() 
{


}