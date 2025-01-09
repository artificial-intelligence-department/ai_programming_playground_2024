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




struct user
{
    std::string name;
    int collected;
    measurement meas;
};

std::string createUsersFormatString(user* users, const size_t& size)
{
    std::string str;
    for (size_t i = 0; i < size; i++)
    {
        str.append(users[i].name + " " + std::to_string(users[i].collected) + " " + std::to_string(users[i].meas));
    }
    
}

user parseUser(std::string lineToParse) // alex 1912194 meter
{
    std::istringstream iss(lineToParse);
    std::string s;
    std::string els[3];
    unsigned int index = 0;
    while ( getline( iss, s, ' ' ) ) {
        els[index++] = s;
    }
    user u;
    u.name = els[0];
    u.collected = std::stoi(els[1]);
    u.meas = parseMeasurement(els[2]);
    return u;
}

bool isPalindrome(int distance)
{
    std::string distanceStr = std::to_string(distance);
    for (size_t i = 0; i < distanceStr.size()/2; i++)
    {
        if(distanceStr[i] != distanceStr[distanceStr.size()-1-i]) return false;
    }
    return true;
    
}

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

    //Gettig price of each unit
    std::string coefBuffer;
    meterFile >> coefBuffer;
    pricePerMeter = std::stod(coefBuffer);
    mileFile >> coefBuffer;
    pricePerMi = std::stod(coefBuffer);
    mileUsFile >> coefBuffer;
    pricePerMiUs = std::stod(coefBuffer);
    

    std::cout << "Enter order distance: ";
    std::cin >> distance;
    std::cin.ignore();
    std::cout << "Do you want to reedem current bonuses (y/n) : ";
    getline(std::cin, tmpString);
    wantGetBonuses = tmpString == "y" ? true : false;
    unsigned int bonuses = 0;
    double finalPrice;
    switch (currentMeasure)
    {
    case measurement::meter:
        finalPrice = pricePerMeter * distance;
        break;
    case measurement::mile:
        finalPrice = pricePerMi * distance;
        break;
    case measurement::mile_us:
        finalPrice = pricePerMiUs * distance;
        break;
    
    default:
        break;
    }

    //Read existing records in FIle to array users
    std::ifstream collectedInfo("C:\\IT\\Politex\\Epic_1\\src\\ai_programming_playground_2024\\ai_12\\nazar_kryvychko\\saga_2\\liveCoding_2\\collected_distances.txt");
    std::ofstream collectedInfoOut("C:\\IT\\Politex\\Epic_1\\src\\ai_programming_playground_2024\\ai_12\\nazar_kryvychko\\saga_2\\liveCoding_2\\collected_distances.txt");
    std::string fileLine;
    user* users;
    int count = 0;
    while(std::getline(collectedInfo,fileLine))
    {
        count++;
    }

    users = new user[count];
    unsigned int index = 0;

    //TO the start
    collectedInfo.clear();
    collectedInfo.seekg(0);
    while(std::getline(collectedInfo,fileLine))
    {
        users[index++] = parseUser(fileLine);
    }

    //Palindrome bonus
    if(isPalindrome(distance))
    {
        bonuses += 2;
    }


    if(wantGetBonuses)
    {
        for (size_t i = 0; i < count; i++)
        {
            if(users[i].name == name)
            {

                int collectedBonuses =  (int) (users[i].collected / 100);
                bonuses += collectedBonuses;
                // Redem bonuses
                users[i].collected -= (collectedBonuses * 100);
                goto AfterPOINT;
            }
        }
        std::cerr << "User not found!\n";
        
    }
    AfterPOINT:
    //Rewrite current file:




    // Generating identifier
    std::string nameCopy = name;
    bubbleSort(nameCopy, name.size());
    double* userIdentifier = identifier(nameCopy.c_str(), name.size());



    std::cout << "Your discount: " << bonuses << "$" << std::endl;
    std::cout << "Order Price: " << finalPrice << "$" << std::endl;
    std::cout << "Final Price: " << finalPrice - bonuses << "$" << std::endl;

    

    
    meterFile.close();
    mileFile.close();
    mileUsFile.close();
    collectedInfo.close();

    delete[] userIdentifier;
    delete[] users;

    return 0;
}