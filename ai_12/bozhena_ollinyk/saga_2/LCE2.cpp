// * Ви отримали своє перше завдання на новій роботі програмістом у
//  * міжнародній логістичній компанії, що здійснює доставку між відділеннями.
//  * Раніше офіси компанії працювали незалежно і лише в межах однієї країни,
//  * але компанія запустила послугу "Комбінована доставка" і тепер розрахунок вартості
//  * відбувається згідно тарифікації, що зберігається у файлах.
//  * Все б нічого, але офіси використовують 3 різні системи вимірювання відстані:
//  * - імперська (британська миля) == 1 609.344 метра; // mi
//  * - миля США (US survey mile) == 1 609.347 метра; // mi_US
//  * - метрична система виміру == 1 метр. // m
//  *
//  * Розробити програму для розрахунку вартості доставки,
//  * яка буде використовувати ідентифікатор користувача та накопичувати відстані.
//  * Компанія встановила наступні бонуси:
//  * Якщо відстань відправлення є паліндромом, то користувач отримує +200 км бонусів.
//  * Кожні накопичені 100км це 1$ знижки. Після використання накопичена відстань зменшується.
//  * При обрахунку вартості запропонувати користувачу скористатись конвертацією накопичених бонусів.

//  * Для формування ідентифікатора користувача використати наступний розрахунок:
//     1. Відсортувати буĸви вашого імені за зростанням.
//     2. Створити одновимірний масив на основі цілочисельного(int) значення
//     символів (ASCII Value) помноженого на 0.4.

//     3. У попередньому масиві залишити лише елементи з індеĸсами від 1 до 3.
//     Створити двовимірний масив 5х3 на основі цілочисельного(int) значення
//     символів (ASCII Value) отриманих у попередньому завданні,
//     а решта значень заповнюються дійсними числами(float).
//     Перемножити ці дві матриці.
//     Результат записати у файл.
//  */

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

bool isPalindrome(int num)
{
    if (num < 0)
        return false;

    if (num >= 0 && num <= 9)
        return true;

    int digits = static_cast<int>(log10(num)) + 1;
    int divisor = 1;

    for (int i = 0; i < digits - 1; ++i)
    {
        divisor *= 10;
    }

    while (num != 0)
    {
        int firstDigit = num / divisor;
        int lastDigit = num % 10;

        if (firstDigit != lastDigit)
        {
            return false;
        }

        num = (num % divisor) / 10;
        divisor /= 100;
    }

    return true;
}

int distanceInMeters(double value, string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        double type;
        file >> type;
        double distance = value * type;
        file.close();
        return distance;
    }
    else
    {
        cout << "Can`t open file" << endl;
        return 1;
    }
}

double simulateMoneyPrecision(double value)
{
    return round(value * 100.0) / 100.0;
}

void sortString(string &s)
{

    int charCount[100] = {0};

    for (int i = 0; i < s.length(); i++)
    {

        charCount[s[i] - 'a']++;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < charCount[i]; j++)
        {
            cout << (char)('a' + i);
        }
    }
}

int returnVal(char x)
{
    return (int)x - 87;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    ofstream file("price_per_meter.txt");
    if (file.is_open())
    {
        const int m = 1;
        file << m;
        file.close();
    }
    else
    {
        cout << "Can`t open or create file" << endl;
    }
    ofstream file2("price_per_mile.txt");
    if (file2.is_open())
    {
        double mi = 1609.344;
        file2 << mi;
        file2.close();
    }
    else
    {
        cout << "Can`t open or create file" << endl;
    }
    ofstream file3("price_per_mile_us.txt");
    if (file3.is_open())
    {
        double mi_US = 1609.347;
        file3 << mi_US;
        file3.close();
    }
    else
    {
        cout << "Can`t open or create file" << endl;
    }

    bool op = true;
    do
    {
        string userName, measurementSystem, convertBonus;

        cout << "Введіть ваше ім'я: ";
        cin >> userName;

        sortString(userName);

        int arr[userName.length()];

        for (int i = 0; i < userName.length(); i++)
        {
            arr[i] = returnVal(userName[i]) * 0.4;
        }

        bubbleSort(arr, userName.length());
        int *redactedarr;
        for (int i = 0; i < userName.length(); i++)
        {
            if (arr[i] <= 3 && arr[i] >= 1)
            {
                redactedarr[i] = arr[i];
            }
        }

        float newarr[5][3];
        for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < sizeof(arr) / sizeof(*arr); k++)
                {

                    newarr[i][j] = redactedarr[j];
                }
                newarr[i][j] = redactedarr[j];
            }
        }
        int i = 0, j = 0;
        while (i < 5 && i < sizeof(arr) / sizeof(*arr))
        {
            newarr[i][j] = redactedarr[j];
            i++;
        }
        if (i >= 5)
        {
            j++;
            i = 0;
            while (i < 5 && i < sizeof(arr) / sizeof(*arr))
            {
                newarr[i][j] = redactedarr[j];
                i++;
            }
        }
        if (i >= 5)
        {
            j++;
            i = 0;
            while (i < 5 && i < sizeof(arr) / sizeof(*arr))
            {
                newarr[i][j] = redactedarr[j];
                i++;
            }
        }

        float mnoz[5][3];
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    mnoz[i][j] += redactedarr[i] * newarr[k][j];
                }
            }
        }

        cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
        cin >> measurementSystem;

        int deliveryDistanceInMeters;

        if (measurementSystem == "meter")
        {
            int distanceValue;
            cout << "Введіть відстань: ";
            cin >> distanceValue;
            deliveryDistanceInMeters = distanceValue;
        }
        else
        {
            double distanceValue;
            cout << "Введіть відстань: ";
            cin >> distanceValue;

            string filename;
            if (measurementSystem == "mile")
            {
                filename = "price_per_mile.txt";
            }
            else
            {
                filename = "price_per_mile_us.txt";
            }

            deliveryDistanceInMeters = distanceInMeters(distanceValue, filename);
        }

        int bonuses;

        if (isPalindrome(deliveryDistanceInMeters))
        {
            bonuses += 200000;
        }

        cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
        cin >> convertBonus;

        // cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
        // cout << "Ваша знижка: " << discount << "$" << endl;
        // cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
        // cout << "Вартість відправки: " << totalPrice << "$" << endl;

        string oper;
        cout << "Бажаєте здійснити ще одну операцію? (y/n)" << endl;
        cin >> oper;
        if (oper == "n" || oper == "no")
        {
            op = false;
        }
    } while (op);

    return 0;
}