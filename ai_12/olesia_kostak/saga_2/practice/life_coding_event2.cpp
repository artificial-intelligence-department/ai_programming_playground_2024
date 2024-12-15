#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>

int calculate_bonuses(int distance);

const char* file_meter = "price_per_meter.txt"; //using pointers and const
const char* file_mile = "price_per_mile.txt";
const char* file_mile_us = "price_per_mile_us.txt";
const char* file_collected_distance = "collected_distance.txt";

int main()
{
    double mi = 1609.344; //suing double
    double mi_US = 1609.347;
    double meter;
    double convertBonus;
    int bonuses = 0;
    int distanceValue; //using int
    std::string measurementSystem;
    std::string userName;

    std::cout << "Введіть ваше ім'я: ";
    std::cin >> userName;

    std::cout << "Введіть відстань: ";
    std::cin >> distanceValue;

    std::cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    std::cin >> measurementSystem;
    std::cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    std::cin >> convertBonus;

    //знаходження ідентифікатора
    int size_of_name = userName.size();
    int arr[size_of_name]; //using one-dimentional array
    for (int i = 0; i < size_of_name - 1; i++)
    {
        for (int j = 0; j < size_of_name - 1; j++)
        {
            if (int(userName[j]) > int(userName[j+1]))
            {
                char temp = userName[j];
                userName[j] = userName[j + 1];
                userName[j + 1] = temp;
            }
        }
        arr[i] = int(userName[i]) * 0.4;
    }
    arr[size_of_name - 1] = userName[size_of_name - 1] * 0.4;

    if (measurementSystem == "meter") //using if
    {
        bonuses += calculate_bonuses(distanceValue);
        
    } 
    else if (measurementSystem == "mile")
    {

    }
    else if (measurementSystem == "mile_us")
    {

    }
    else
    {
        std::cout << "Your metric system is not correct" << std::endl;
        return 0;
    }



    return 0;
}

void write_to_file(int indetifier[], int size, const char* filename, int price)
{
    std::ofstream myfile(filename);
    if (myfile.is_open())
    {
        myfile << "Indentifier: ";
        for (int i = 0; i < size-1; i++)
        {
            myfile << indetifier[i];
        }
        myfile << std::endl;
        myfile << "Price: " << price;
    }
    else
    {
        perror("Error opening file");
        exit (1);
    }
}
int calculate_bonuses(int distance)
{
    if (isPalindrome(distance))
    {
        return 200;
    }
}

double simulateMoneyPrecision(double value) {
    return std::round(value * 100.0) / 100.0;
}

bool isPalindrome(int num)
{
    if(num < 0)
        return 0;

    int temp = num;
    int reversed = 0;

    while (temp > 0)
        {
            reversed = (temp % 10) + (reversed * 10);
            temp /= 10;
        }
    return reversed == num; 
}

int read_from_file(int price, const char* filename, int indetifier[], int size)
{
    std::ifstream myfile(filename);
    if (myfile.is_open())
    {
        std::string buffer;
        while (getline(myfile, buffer))
        {
        }
    
    }
    else
    {
        exit(1);
    }
}



/**
 * Ви отримали своє перше завдання на новій роботі програмістом у
 * міжнародній логістичній компанії, що здійснює доставку між відділеннями.
 * Раніше офіси компанії працювали незалежно і лише в межах однієї країни,
 * але компанія запустила послугу "Комбінована доставка" і тепер розрахунок вартості
 * відбувається згідно тарифікації, що зберігається у файлах.
 * Все б нічого, але офіси використовують 3 різні системи вимірювання відстані:
 * - імперська (британська миля) == 1 609.344 метра; // mi
 * - миля США (US survey mile) == 1 609.347 метра; // mi_US
 * - метрична система виміру == 1 метр. // m
 *
 * Розробити програму для розрахунку вартості доставки,
 * яка буде використовувати ідентифікатор користувача та накопичувати відстані.
 * Компанія встановила наступні бонуси:
 * Якщо відстань відправлення є паліндромом, то користувач отримує +200 км бонусів.
 * Кожні накопичені 100км це 1$ знижки. Після використання накопичена відстань зменшується.
 * При обрахунку вартості запропонувати користувачу скористатись конвертацією накопичених бонусів.

 * Для формування ідентифікатора користувача використати наступний розрахунок:
    1. Відсортувати буĸви вашого імені за зростанням.
    2. Створити одновимірний масив на основі цілочисельного(int) значення
    символів (ASCII Value) помноженого на 0.4.
    Результат записати.
 */

