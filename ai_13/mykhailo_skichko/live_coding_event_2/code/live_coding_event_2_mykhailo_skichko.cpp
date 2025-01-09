#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

const std::string MAIN_FILE_NAME = "collected_distance.txt";
const double METERS_IN_MLE = 1609.344;
const double METERS_IN_US_MLE = 1609.347;

struct User
{
    std::string name;
    double accumulatedDistance = 0.0;
    double discount = 0.0;
};

void bubbleSort(std::string &str)
{
    for (size_t i = 0; i < str.length() - 1; ++i)
    {
        for (size_t j = 0; j < str.length() - 1; ++j)
        {
            if (str[j] > str[j + 1])
            {
                std::swap(str[j], str[j + 1]);
            }
        }
    }
}

int createUserId(const std::string &name)
{
    std::string nameSorted = name;
    bubbleSort(nameSorted);

    double id = 0.0;
    for (char ch : nameSorted)
    {
        id += static_cast<int>(ch) + 0.4;
    }
    return static_cast<int>(id);
}

double convertToMeters(double distance, const std::string &measurementSystem)
{
    if (measurementSystem == "meter")
    {
        return distance;
    }
    else if (measurementSystem == "mile")
    {
        return distance * METERS_IN_MLE;
    }
    else if (measurementSystem == "mile_us")
    {
        return distance * METERS_IN_US_MLE;
    }
    else
    {
        throw std::invalid_argument("Wrong measurement system / unit.");
    }
}

bool isPalindrome(int value)
{
    std::string str = std::to_string(value);
    int N = str.length();
    for (size_t i = 0; i < N; ++i)
    {
        if (str[i] == str[N - i - 1])
        {
            return false;
        }
    }
    return true;
}

void writeToFile(const std::string &fileName, int userId, double distance)
{
    std::ofstream outFile(fileName, std::ios::app);
    if (outFile.is_open())
    {
        outFile << userId << "\t" << distance << std::endl;
        outFile.close();
    }
    else
    {
        std::cerr << "Can't open file for writing." << std::endl;
    }
}

double simulateMoneyPrecision(double value)
{
    return std::round(value * 100.0) / 100.0;
}

double readPricePerUnit(const std::string &fileName)
{
    std::ifstream inFile(fileName);
    double price = 0.0;
    if (inFile.is_open())
    {
        inFile >> price;
        inFile.close();
    }
    else
    {
        throw std::runtime_error("Unable to open price file.");
    }
    return price;
}

int main()
{
    User user;
    std::cout << "Введіть ваше ім'я: ";
    std::cin >> user.name;

    int userId = createUserId(user.name);

    double distance;
    std::string measurementSystem;

    std::cout << "Введіть відстань: ";
    std::cin >> distance;
    std::cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    std::cin >> measurementSystem;

    /*
    std::cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << std::endl;
    std::cout << "Ваша знижка: " << discount << "$" << std::endl;
    std::cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << std::endl;
    std::cout << "Вартість відправки: " << totalPrice << "$" << std::endl;
    */

    return 0;
}
