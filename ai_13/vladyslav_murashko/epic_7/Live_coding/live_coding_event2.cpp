#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

const float mi = 1609.344;
const float mi_US = 1609.347;
const string FILE_NAME = "collected_distance.txt";

struct User
{
    string Id;
    double value;
};

string generateId(string name)
{
    int arr[name.length()];
    for (size_t i = 0; i < name.length(); i++)
    {
        arr[i] = name[i] * 0.4;
    }

    for (size_t i = 0; i < name.length(); i++)
    {
        for (size_t j = i + 1; j < name.length(); j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    string returnstring = "";
    for (int i = 0; i < name.length(); i++)
        returnstring += to_string(arr[i]);
    return returnstring;
}

double simulatePrecision(double value)
{
    return std::round(value * 100.0) / 100.0;
}

int distanceInMeters(User user, double value);

void saveInfo(string id, double distance)
{
    ofstream file(FILE_NAME, ios_base::app);
    if (file)
    {
        file << id << " " << simulatePrecision(distance) << endl;
        file.close();
    }
}

User logIn(string name)
{
    ifstream file(FILE_NAME);
    User user;
    user.Id = "0";
    string id = generateId(name);
    if (file)
    {
        string data;
        while (file >> data)
            if (id.compare(data) == 0)
            {
                user.Id = id;
                file >> data;
                user.value = stod(data);
                file.close();
                return user;
            }
            else
            {
                file >> data;
            }
    }
    file.close();
    return user;
}

double getDistanceIfLogin()
{
    ifstream file(FILE_NAME);
    if (file)
    {
        string data;
        file >> data;
        file >> data;
        file.close();
        return stod(data);
    }
    return 0;
}

void checkBonuses(User user, double distance)
{
    string str = to_string(distance);
    bool isPalindrome = true;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
    {
        user.value += 200000;
    }
}

double getPriceByType(string type)
{
}

double calculateMaxDiscount(User user)
{
    return simulatePrecision(user.value / 100);
}

double calculateSumWithDiscount(User user, double distance, string type)
{
    return
}

double calculateSum(double distance, string type)
{
}

int main()
{
    User user;

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    user = logIn(name);
    if (user.Id == "0")
    {
        user.Id = generateId(name);
        user.value = 0;
    }

    double distance;
    cout << "Enter the distance: ";
    cin.ignore();
    cin >> distance;
    string system;
    do
    {
        cout << "Choose the metric system (meter/mile/mile_us):";
        cin >> system;
    } while (system != "meter" || system != "mile" || system != "mile_us");
    if (system == "meter")
    {
        user.value += simulatePrecision(distance);
    }
    else if (system == "mile"){

    }
    else{
        
    }

    char convertBonus;
    do
    {
        cout << "Do you want to convert bonuses (y/n)? ";
        cin >> convertBonus;
    } while (convertBonus != 'y' || convertBonus != 'n');

    return 0;
}