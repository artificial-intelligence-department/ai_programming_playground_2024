#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

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

 */


// For switch case simplicity
enum measurement {
    mile , mile_us , meter , none
};

void bubbleSort(std::string arr, const size_t& size)
{
    int n = size;
    bool swapped;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
      
        if (!swapped)
            break;
    }
}

double* identifier(const char* array, const size_t& size)
{
    double* identifierPtr = new double[size];
    for (size_t i = 0; i < size; i++)
    {
        identifierPtr[i] = static_cast<double>(((static_cast<int>(array[i])) * 0.4));
    }
    return identifierPtr;
}

measurement parseMeasurement(std::string measurementStr)
{
    if(measurementStr == "mile")
    {
        return measurement::mile;
    }
    else if (measurementStr == "mile_us")
    {
        return measurement::mile_us;
    }
    else if(measurementStr == "meter")
    {
        return measurement::meter;
    }
    else 
    {
        return measurement::none;
    }
}

int main(void)
{
    std::string name , measurementSystem, tmpString;
    double distance;
    bool wantGetBonuses;


    std::cout << "Enter your name: ";
    getline(std::cin, name);

    M_POINT:
    std::cout << "Enter your measurement system (meter/mile/mile_us): ";
    getline(std::cin, measurementSystem);
    std::cout << measurementSystem;
    measurement currentMeasure = parseMeasurement(measurementSystem);
    // Edge case
    if(currentMeasure == measurement::none)
    {
        std::cerr << "Bad measurement system , try again!\n";
        goto M_POINT;
    }


    //Open Files 
    std::ifstream meterFile("C:\\IT\\Politex\\Epic_1\\src\\ai_programming_playground_2024\\ai_12\\nazar_kryvychko\\saga_2\\liveCoding_2\\price_per_meter.txt");
    std::ifstream mileFile("C:\\IT\\Politex\\Epic_1\\src\\ai_programming_playground_2024\\ai_12\\nazar_kryvychko\\saga_2\\liveCoding_2\\price_per_mile.txt");
    std::ifstream mileUsFile("C:\\IT\\Politex\\Epic_1\\src\\ai_programming_playground_2024\\ai_12\\nazar_kryvychko\\saga_2\\liveCoding_2\\price_per_mile_us.txt");


    const double mi = 1609.344 , mi_US = 1609.347 , m = 1; 
    double pricePerMi, pricePerMiUs , pricePerMeter;

    //Gettig coefs in respect to meter
    std::string coefBuffer;
    meterFile >> coefBuffer;
    pricePerMeter = std::stod(coefBuffer);
    mileFile >> coefBuffer;
    pricePerMi = std::stod(coefBuffer);
    mileUsFile >> coefBuffer;
    pricePerMiUs = std::stod(coefBuffer);
    

    std::cout << "Enter order distance: ";
    std::cin >> distance;
    std::cout << "Do you want to reedem current bonuses (y/n) : ";
    getline(std::cin, tmpString);
    wantGetBonuses = tmpString == "y" ? true : false;
    unsigned int bonuses = 0;
    if(wantGetBonuses)
    {
        // ... TODO redeem current bonuses
    }

    // Generating identifier
    std::string nameCopy = name;
    bubbleSort(nameCopy, name.size());
    double* userIdentifier = identifier(nameCopy.c_str(), name.size());


    

    delete[] userIdentifier;

    return 0;
}