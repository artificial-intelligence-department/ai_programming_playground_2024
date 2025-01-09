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

#include <iostream>
#include <iomanip>   
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}


bool isPalindrome(int num)
{
    if (num<0)
    {
        return 0;
    }
    int original = num; 
    int reversed = 0;
    int digit;

    while (num != 0) {
        digit = num % 10;
        reversed = reversed * 10 + digit;  
        num /= 10;  
    }
    return original == reversed; 
}

int main()
{
    string userName;
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    int distanceValue;
    cout << "Введіть відстань: ";
    cin >> distanceValue;
    string measurementSystem;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;
    for (int i = 0; i < userName.length(); i++)
    {
        bool isChanged = 0;
        for (int j = 0; j < userName.length()-1; j++)
        {
            if (userName[j]> userName[j+1])
            {
                swap(userName[i], userName[i+1]); 
                isChanged=1;
            }
        }   
        if (!isChanged)
        {
            break;
        }
    }
    double arr[userName.length()];  //дійсний з подвійною точністю; одновимірний масив 
    for (int i = 0; i < userName.length(); i++) //for цикл
    {
        arr[i] = (double) userName[i]*0,4;
        simulateMoneyPrecision(arr[i]);
    }
    
    int bonuses;

    if(isPalindrome(distanceValue))  
    {
        bonuses += 2; 
    }

    bonuses += distanceValue / 100000;
    

    
}