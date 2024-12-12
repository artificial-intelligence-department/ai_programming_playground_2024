#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double BritishMile = 1609.344;
const double AmericahMile = 1609.347;
// в коді використана як мінімум одна цілочисельна константа
const int maxSize = 100;
string fileName = "collected_distance.txt";

bool isPalindrome(int dist)
{
    // в коді використана як мінімум одна цілочисельна змінна
    int temp = dist;
    int reverse = 0;
    while ((dist > 0))
    {
        // в коді використано математичні операції та математичні функції
        reverse = reverse * 10 + dist % 10;
        dist /= 10;
    }
    return temp == reverse;
}
// в коді використано параметри та аргументи функції
double converting(double dist, string choice)
{
    // в коді використані умовні оператори та розгалуження

    if (choice == "mile")
    {
        return dist * BritishMile;
    }
    else if (choice == "mile_us")
    {
        return dist * AmericahMile;
    }
    else if (choice == "meter")
    {
        return dist;
    }
}

double bonusToTk(double bonus)
{
    return bonus * 200;
}

void bubbleSort(string &name)
{
    int k = name.length();
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = k - 1; j > i; j--)
        {
            if (name[j] < name[j - 1])
            {
                swap(name[j], name[j - 1]);
            }
        }
    }
}

void createID(string &name, int result[])
{
    string sortedName = name;
    bubbleSort(sortedName);
    // в коді використаний for цикл
    for (int i = 0; i < sortedName.size(); i++)
    {
        result[i] = (static_cast<int>(sortedName[i]) * 0.4);
    }
}

double simulateMoneyPrecision(double value)
{
    return std::round(value * 100.0) / 100.0;
}

bool readFiles(string &filename, double rate)
{
    // в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    ifstream fileStream(filename);
    if (!fileStream.is_open())
    {
        cout << "Error!" << endl;
        return false;
    }
    double line;
    // в коді використаний while цикл
    while (!fileStream.eof())
    {
        fileStream >> line;
        rate = line;
    }

    fileStream.close();
    return true;
}

double calculateCost(double distanceInMetres, double rate, double &distance, bool usedBonuses)
{
    if (isPalindrome(static_cast<int>(distanceInMetres)))
    {
        distance += 200000;
    }

    double cost = distanceInMetres * rate;

    if (usedBonuses)
    {
        int discount = static_cast<int>(distance / 100000);
        cost -= discount;
        if (cost < 0)
        {
            cost = 0;
        }
        distance -= discount * 100000;
    }
    return simulateMoneyPrecision(cost);
}

int main()
{
    string userName;
    float distanceValue;
    string measurementSystem;
    char choice;
    // в коді використана як мінімум одна дійсна змінна
    double dist = 0.0;
    // в коді використано оператори виведення та введення даних
    cout << "Введіть ваше ім'я: ";
    cin >> userName;

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;
    // в коді використаний одновимірний масив
    int id[maxSize];
    createID(userName, id);
    double distanceInMetres = converting(distanceValue, measurementSystem);
    // в коді використана як мінімум одна дійсний з подвійною точністю змінна
    double rate = 0.0;
    if (measurementSystem == "mile")
    {
        rate = BritishMile;
    }
    else if (measurementSystem == "mile_us")
    {
        rate = AmericahMile;
    }
    else if (measurementSystem == "meter")
    {
        rate = 1.0;
    }
    cout << "Do you want to convert bonuses in distance?(y/n)" << endl;
    cin >> choice;
    bool usebonuses = false;
    if (choice == 'y' || choice == 'Y')
    {
        bool usebonuses = true;
    }
    double cost = calculateCost(distanceInMetres, rate, dist, usebonuses);
    cout << "Price: " << cost << endl;
    cout << "Distance: " << dist << endl;
    // в коді використано функції роботи з файлами, для того, щоб записати у файл
    ofstream fileStream("result.txt");
    if (!fileStream.is_open())
    {
        cout << "Error!" << endl;
    }
    fileStream << "ID:" << userName << endl;
    fileStream.close();
}