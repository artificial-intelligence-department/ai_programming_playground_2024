#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
int getFirstDigit(int number)
{

    while (number >= 10)
    {
        number /= 10;
    }

    return number;
}

bool isPalindrom(int num)
{
    bool isPal = true;
    int start = getFirstDigit(num);
    int end = num % 10;

    if (static_cast<int>(to_string(num).length()) <= 1)
    {
        return true;
    }
    if (start != end)
    {
        return false;
    }

    if (start == end)
    {
        num /= 10;
        num %= static_cast<int>(pow(10, static_cast<int>(log10(num))));
        return isPalindrom(num);
    }
    return true;
}
double convertToKM(string str, double distance)
{
    if (str == "Meters")
    {
        return distance / 1000;
    }
    if (str == "Miles")
    {
        return distance * 1.60934;
    }
    if (str == "MilesUS")
    {
        return distance * 1.609347;
    }
    return 0;
};
int main()
{

    double bonus = 0;

    double pricePerMeter = 0.0005;
    double pricePerMile = 0.8;
    double pricePerMileUs = 1.2;

    string myName;
    cout << "Your name:" << endl;
    cin >> myName;
    string fileName = myName + ".txt";

    int nameInt[150] = {};
    for (int i = 0; i < myName.length(); i++)
    {
        nameInt[i] = 0.4 * myName[i];
    }
    for (int i = 0; i < myName.length(); i++)
    {
        for (int j = 0; j < myName.length(); j++)
        {
            if (nameInt[i] > nameInt[j])
            {
                swap(nameInt[j], nameInt[i]);
            }
        }
    }
    cout << "Distance:" << endl;
    int distance;
    cin >> distance;

    if (isPalindrom(distance))
    {
        bonus += 2;
    }

    cout << "Meters/Miles/MilesUS" << endl;
    string len;
    cin >> len;
    double kilometers = convertToKM(len, distance);
    fstream file(fileName);
    for (int i = myName.length() - 1; i >= 0; i--)
    {
        file << nameInt[i];
    }
    file << "  " << kilometers;
    if (len == "Meters")
    {
        cout << "Delivery price: " << distance * pricePerMeter << endl;
    }
    if (len == "Miles")
    {
        cout << "Delivery price: " << distance * pricePerMile << endl;
    }
    if (len == "MilesUS")
    {
        cout << "Delivery price: " << distance * pricePerMileUs << endl;
    }
    cout << "Do you Want to use your bonuses? (0/1)" << endl;
    bool bon = false;
    cin >> bon;

    string line;
    while (file.getline(line))
    {
    }
    return 0;
}