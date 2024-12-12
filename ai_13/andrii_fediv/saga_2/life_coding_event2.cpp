#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

double transformd(string typef, double value)
{
    if (typef == "meter")
    {
        return value;
    }
    else if (typef == "mile_us")
    {
        return value * 1609.347;
    }
    else if (typef == "mile")
    {
        return value * 1609.344;
    }
}

double transformto(string typef, double value)
{
    if (typef == "meter")
    {
        return value;
    }
    else if (typef == "mile_us")
    {
        return value / 1609.347;
    }
    else if (typef == "mile")
    {
        return value / 1609.344;
    }
}

/*
"price_per_meter.txt", 0.0005

"price_per_mile.txt", 0.8

"price_per_mile_us.txt", 1.2

*/

bool isPalindrome(double distance)
{
    string distStr = to_string(int(distance));
    string reversed = distStr;
    reverse(reversed.begin(), reversed.end());
    return distStr == reversed;
}

double get_tarification(string typef)
{

    if (typef == "meter")
    {
        fstream file("price_per_meter.txt", ios::in);
        if (!file.is_open())
        {
            cout << "file problem\n";
            return 0;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty())
            {
                cout << "empty line\n";
                return 0;
            }
            stringstream ss(line);
            double distance;

            ss >> distance;
            file.close();
            return distance;
        }
    }
    else if (typef == "mile_us")
    {
        fstream file("price_per_mile.txt", ios::in);
        if (!file.is_open())
        {
            cout << "file problem\n";
            return 0;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty())
            {
                cout << "empty line\n";
                return 0;
            }
            stringstream ss(line);
            double distance;

            ss >> distance;
            return distance;
            file.close();
        }
    }
    else if (typef == "mile")
    {
        fstream file("price_per_mile_us.txt", ios::in);
        if (!file.is_open())
        {
            cout << "file problem\n";
            return 0;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty())
            {
                cout << "empty line\n";
                return 0;
            }
            stringstream ss(line);
            double distance;

            ss >> distance;
            return distance;
            file.close();
        }
    }

    return 0;
}

int main()
{

    string userName;
    double distanceValue;
    string measurementSystem;
    string convertBonus;

    cout << "Введіть ваше ім'я: ";
    cin >> userName;

    sort(userName.begin(), userName.end());
    int *idarr = new int[userName.size()];
    string idstr;
    for (int i = 0; i < userName.size(); i++)
    {
        idarr[i] = char(userName[i]) * 0.4;
        cout << idarr[i] << " ";
        idstr += to_string(idarr[i]);
    }
    int id;
    stringstream ss(idstr);
    ss >> id;

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    double tarif = get_tarification(measurementSystem);

    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;
    ///////////////////////////////////////////
    fstream file("collected_distance.txt", ios::in);
    if (!file.is_open())
    {
        cout << "file problem\n";
        return 0;
    }

    double deliveryDistanceInMeters;
    int discount = 0;
    ///////////
    double distance_in_meters = transformd(measurementSystem, distanceValue);
    bool new_user = true;
    double distance;
    vector<string> FILEARR;
    int index = -1;
    string line;
    while (getline(file, line))
    {
        FILEARR.push_back(line);
        if (line.empty())
        {
            cout << "empty line\n";
            return 0;
        }
        stringstream ss(line);
        int id2;

        ss >> id2 >> distance;
        index++;
        if (id == id2)
        {
            new_user = false;
            break;
        }
    }
    file.close();
    if (new_user)
    {
        index++;
        distance = 0;
        string user = to_string(id) + " " + to_string(distanceValue);
        FILEARR.push_back(user);
    }

    deliveryDistanceInMeters = distance + distance_in_meters;
    if (convertBonus == "y")
    {

        while (deliveryDistanceInMeters - 100 >= 0)
        {
            deliveryDistanceInMeters -= 100;
            discount++;
        }
    }

    (FILEARR[index]) = to_string(id) + " " + to_string(deliveryDistanceInMeters);

    if (isPalindrome(deliveryDistanceInMeters))
        deliveryDistanceInMeters += 200000;

    fstream file2("collected_distance.txt", ios::out);
    for (size_t i = 0; i < FILEARR.size(); i++)
    {
        file2 << FILEARR[i] << endl;
    }
    file2.close();

    double deliveryDistanceInKiloMeters = deliveryDistanceInMeters / 1000;
    double totalPrice = tarif * transformto(measurementSystem, deliveryDistanceInMeters) - discount;
    if(totalPrice < 0){
        totalPrice = 0;
    }

    cout << "Відстань поточної доставки: " << distance_in_meters << "m" << endl;
    cout << "Ваша знижка: " << discount << "$" << endl;
    cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
    cout << "Вартість відправки: " << totalPrice << "$" << endl;
    return 0;
}

/**
 * Ви отримали своє перше завдання на новій роботі програмістом у
 * міжнародній логістичній компанії, що здійснює доставку між
відділеннями.
 * Раніше офіси компанії працювали незалежно і лише в межах однієї
країни,
 * але компанія запустила послугу "Комбінована доставка" і тепер
розрахунок вартості
 * відбувається згідно тарифікації, що зберігається у файлах.


 * Все б нічого, але офіси використовують 3 різні системи вимірювання
відстані:
 * - імперська (британська миля) == 1 609.344 метра; // mi
 * - миля США (US survey mile) == 1 609.347 метра; // mi_US
 * - метрична система виміру == 1 метр. // m
 *
 *
 * Розробити програму для розрахунку вартості доставки,
 * яка буде використовувати ідентифікатор користувача та накопичувати
відстані.
 * Компанія встановила наступні бонуси:
 * Якщо відстань відправлення є паліндромом, то користувач отримує +200
км бонусів.
 * Кожні накопичені 100км це 1$ знижки. Після використання накопичена
відстань зменшується.
 * При обрахунку вартості запропонувати користувачу скористатись
конвертацією накопичених бонусів.
 * Для формування ідентифікатора користувача використати наступний
розрахунок:
 1. Відсортувати буĸви вашого імені за зростанням.
 2. Створити одновимірний масив на основі цілочисельного(int)
значення
 символів (ASCII Value) помноженого на 0.4.
 */