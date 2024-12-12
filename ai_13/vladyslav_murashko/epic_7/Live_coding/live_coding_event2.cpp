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

void updateInfo(User user)
{
    string info = "";
    ifstream file(FILE_NAME);
    if (file)
    {
        string data;
        while (file >> data)
        {

            info += data + " ";
            if (user.Id.compare(data) == 0)
            {
                file >> data;
                info += to_string(user.value) + "\n";
            }
            else
            {
                file >> data;
                info += data + "\n";
            }
        }
        file.close();
    }

    ofstream file2(FILE_NAME);
    if (file2)
    {
        file2 << info;
        file2.close();
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

void checkBonuses(User& user, double distance)
{
    string str = to_string((int)round(distance));
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
    string tmp;
    if (type == "meter")
    {
        tmp = "price_per_meter.txt";
    }
    else if (type == "mile")
    {
        tmp = "price_per_mile.txt";
    }
    else
    {
        tmp = "price_per_mile_us.txt";
    }
    ifstream file(tmp);
    file >> tmp;
    return stod(tmp);
}

double calculateMaxDiscount(User user)
{
    return simulatePrecision(user.value / 100000);
}

double calculateSum(User& user, double distance, string type)
{
    double disc = calculateMaxDiscount(user);
    double price = distance * getPriceByType(type);
    if (price < disc)
    {
        user.value -= price * 100000;
        return 0;
    }
    else
    {
        user.value = 0;
        return price - disc;
    }
}

double calculateSum(double distance, string type)
{
    return distance * getPriceByType(type);
}

int main()
{
    User user;

    string name;
    cout << "Enter your name: ";
    cin >> name;
    user = logIn(name);
    if (user.Id == "0")
    {
        user.Id = generateId(name);
        user.value = 0;
        saveInfo(user.Id, user.value);
    }

    double distance;
    cout << "Enter the distance: ";
    cin >> distance;
    string system;
    do
    {
        cout << "Choose the metric system (meter/mile/mile_us): ";
        cin >> system;
    } while (system.compare("mile_us") != 0 && system.compare("mile") != 0 && system.compare("meter") != 0);

    char convertBonus;
    do
    {
        cout << "Your bonuses: " << calculateMaxDiscount(user) << endl;
        cout << "Do you want to convert bonuses (y/n)? ";
        cin >> convertBonus;
    } while (convertBonus != 'y' && convertBonus != 'n');

    switch (convertBonus)
    {
    case 'y':
        cout << "Total cost with bonuses is: " << calculateSum(user, distance, system);
        break;
    case 'n':
        cout << "Total cost without bonuses is: " << calculateSum(distance, system);
        break;
    }

    if (system == "meter")
    {
        user.value += simulatePrecision(distance);
    }
    else if (system == "mile")
    {
        user.value += simulatePrecision(distance * mi);
    }
    else
    {
        user.value += simulatePrecision(distance * mi_US);
    }
    checkBonuses(user, distance);
    updateInfo(user);

    return 0;
}