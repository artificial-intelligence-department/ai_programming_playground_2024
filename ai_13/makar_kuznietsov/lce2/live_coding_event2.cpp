#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define VARIANT 68

std::string identMaker(std::string name);
void writeToFile(std::string name, std::string ident, int distance, int measureUnit);
bool checkPalindrome(int distance);
std::string checkIfInFile(std::string ident);

int main()
{
    std::string name;
    std::cout << "enter name: ";
    std::cin >> name;
    std::string identifier = identMaker(name);

    int measurementSystem;
    do
    {
        std::cout << "choose measurement unit (1 - meter / 2 - mile / 3 - mile_us): ";
        std::cin >> measurementSystem;
    } while (measurementSystem != 1 && measurementSystem != 2 && measurementSystem != 3);

    int distanceValue;
    std::cout << "enter distance: ";
    std::cin >> distanceValue;

    std::string bonus = checkIfInFile(identifier);
    if (bonus == "")
    {
        writeToFile(name, identifier, distanceValue, measurementSystem);
    }
}

double simulateMoneyPrecision(double value)
{
    return std::round(value * 100.0) / 100.0;
}

void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

std::string identMaker(std::string name)
{
    std::vector<int> temp;
    for (int i = 0; i < name.length(); i++)
    {
        temp.push_back((int)name[i]);
    }
    bubbleSort(temp);
    std::string result = "";
    for (auto el : temp)
    {
        result += std::to_string((int)(el * 0.4));
    }
    return result;
}

void writeToFile(std::string name, std::string ident, int distance, int measureUnit)
{
    std::ofstream myFile("database.txt", std::ios::app);
    if (!myFile.is_open())
    {
        std::cerr << "cant open file";
        return;
    }
    else
    {
        std::string unit = measureUnit == 1 ? "meter" : (measureUnit == 2 ? "mile" : "mile_us");
        myFile << name << " " << ident << " " << distance << " " << unit << '\n';
    }
    myFile.close();
}

bool checkPalindrome(int distance)
{
    int reverse = 0;
    int temp = distance;
    while (temp != 0)
    {
        reverse = (reverse * 10) + (temp % 10);
        temp /= 10;
    }
    return (reverse == distance);
}

std::string checkIfInFile(std::string ident)
{
    std::ifstream myFile("database.txt");
    bool isInFile = 0;
    std::string accum;
    std::string unit;
    if (!myFile.is_open())
    {
        std::cerr << "cant open file";
    }
    else
    {
        std::string line;
        while (getline(myFile, line))
        {
            std::ifstream ifs(line);
            std::string word;
            while (ifs >> word)
            {
                if (word == ident)
                {
                    isInFile = 1;
                    ifs >> accum;
                    ifs >> unit;
                    break;
                }
            }
            if (isInFile)
            {
                break;
            }
        }
        return std::to_string(unit == "meter" ? (int)(std::stoi(accum) / 1000)
                                              : (unit == "mile" ? (int)(std::stoi(accum) * 1.609344)
                                                                : (int)(std::stoi(accum) * 1.609347)));
    }
    return 0;
}
