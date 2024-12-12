#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double mi_conv = 1609,344;
const double mi_US_conv = 1609,347;

int to_meters (double distance, string units) {
    int meterDistance;

    if (units == "meter") {
        meterDistance = distance;
    }

    if (units == "mile") {
        meterDistance = distance * mi_conv;
    }

    if (units == "mile_us") {
        meterDistance = distance * mi_US_conv;
    }

    return meterDistance;
}

bool is_pali(int& number) {
    string text = to_string(number);
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != text[text.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main () {
    string units;
    char arr[30];
    double distance;

    cout << "Enter your username:\n";
    cin >> arr;
    cout << "Enter distance units(meter/mile/mile_us):\n";
    cin >> units;
    cout << "Enter distance:\n";
    cin >> distance;

    int meterDistance = to_meters(distance, units);

    bool swapped;
    do {
        swapped = false;

        for (int i = 0; i < strlen(arr); i++) {
            for (int j = 1; j < strlen(arr) - 1 - i; j++) {
                if (arr[j] < arr[j+1]) {
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
        }
    } while (swapped);

    double numbers[100];
    for (int i = 0; i < strlen(arr); i++) {
        char temp = arr[i];
        numbers = temp * 0,4;
    }

    ofstream userID("collected_distance.txt", ios::binary);

    userID.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    userID.write(reinterpret_cast<char*>(meterDistance), sizeof(int));
    userID.close();

    int price;
    double coef;

    if (units == "meter") {
        ifstream meterPrice("price_per_meter.txt", ios::binary);
        meterPrice.read(reinterpret_cast<char*>(&coef), sizeof(double));
        price = distance*coef;
        meterPrice.close();
    }

    if (units == "mile") {
        ifstream milePrice("price_per_mile.txt", ios::binary);
        milePrice.read(reinterpret_cast<char*>(&coef), sizeof(double));
        price = distance*coef;
        milePrice.close();
    }

    if (units == "mile_us") {
        ifstream mileUSPrice("price_per_mile_us.txt", ios::binary);
        mileUSPrice.read(reinterpret_cast<char*>(&coef), sizeof(double));
        price = distance*coef;
        mileUSPrice.close();
    }

    bool palindrome = is_pali(meterDistance);

    int collectedBonus = 0;

    if (palindrome) {
        collectedBonus += 2;
    }

    collectedBonus += meterDistance/1000;

    cout << "Your transportation price is " << price << endl;

    ifstream userIDRead("collected_distance.txt", ios::binary);




    userID.close();

    return 0;
}




































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
//  */

