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


    3. У попередньому масиві залишити лише елементи з індеĸсами від 1 до 3.
    Створити двовимірний масив 5х3 на основі цілочисельного(int) значення
    символів (ASCII Value) отриманих у попередньому завданні,
    а решта значень заповнюються дійсними числами(float).
    Перемножити ці дві матриці.
    Результат записати.
 */


#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>



using namespace std;

int main(){
    string line , distanceValue , measurementSystem  ;
     
    
    ofstream fileF1("price_per_meter.txt" );
    ofstream fileF2("price_per_mile.txt");
    ofstream fileF3("price_per_mile_us.txt" );
    fileF1 <<  0.0005;
    fileF2 <<  0.8 ;
    fileF3 <<  1.2;
    fileF1.close();
    fileF2.close();
    fileF3.close();

    ifstream rF1("price_per_meter.txt" );
    ifstream rF2("price_per_mile.txt");
    ifstream rF3("price_per_mile_us.txt");

     if (!rF2.is_open() || !rF3.is_open() || !rF1.is_open()){
        cout << "Не вдалося відкрити файл  F1!" << endl;
        exit(0);
    }

    getline( rF1 , line );
    cout << line  << endl ;
    getline( rF2 , line );
    cout << line  << endl ;
    getline( rF3 , line ); // година
    cout << line << endl ;

    rF1.close();
    rF2.close();
    rF3.close();

    char userName[64];
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;


    return 0;
}