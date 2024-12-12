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
    результат записати
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;
double simulateMoneyPrecision(double value)
{
    return round(value * 100.0) / 100.0;
}
string identifier(string name)
{
    char n[name.length() + 1], temp;
    strcpy(n, name.c_str());
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 1; i < name.length(); i++)
        {
            if (name[i - 1] > name[i])
            {
                swap = true;
                temp = name[i - 1];
                name[i - 1] = name[i];
                name[i] = temp;
            }
        }
    }
    string result = "";
    for(int i = 0; i < name.length(); i++)
    {
        n[i] = name[i]*0.4;
        result.append(to_string(n[i]));
    }
    
    return result;
}
int main()
{
    ofstream price_per_meter("price_per_meter.txt");
    price_per_meter << 0.0005;
    price_per_meter.close();
    ofstream price_per_mile("price_per_mile.txt");
    price_per_mile << 0.8;
    price_per_mile.close();
    ofstream price_per_mile_us("price_per_mile_us.txt");
    price_per_mile_us << 1.2;
    price_per_mile_us.close();
    fstream collected_distance("collected_distance.txt", ios::in | ios::out | ios::app);

    string userName, measurementSystem;
    char y_n;
    float distanceValue;
    bool use_bonus = false;
    cout << "Name: ";
    cin >> userName;
    cout << endl
         << "Distance: ";
    cin >> distanceValue;
    cout << endl
         << "Measurement system:(meter/mile/mile_us): ";
    cin >> measurementSystem;
    cout << endl
         << "Use your bonuses? (y/n): ";
    cin >> y_n;
    if (y_n == 'y')
        use_bonus = true;
    string id = identifier(userName);
    string word, line;
    string current_distance = "0";
    int distanceValue_m = 0;
    streampos oldpos = collected_distance.tellg();
    while(getline(collected_distance, line, '\n'))
    {
        stringstream ss(line);
        getline(ss, word, ' ');
        if(word == id)
        {
            getline(ss, current_distance);
            collected_distance.seekp(oldpos);
            collected_distance << distanceValue_m;
            
        }
        oldpos = collected_distance.tellg();
    }
    return 0;
}