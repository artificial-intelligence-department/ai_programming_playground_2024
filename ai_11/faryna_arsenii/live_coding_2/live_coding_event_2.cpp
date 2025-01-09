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
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const double MI = 1609.344; // use const 
const double MU_US = 1609.347;
const double M = 1;

bool isPalindrom(int distance) {

    string str = to_string(distance); 
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str; 

}

vector<vector<float>> generateUserID(const string& name){

    // Відсортувати буĸви вашого імені за зростанням.
    string SortedName = name;
    sort(SortedName.begin(), SortedName.end());
    // Створити одновимірний масив на основі цілочисельного(int) значення символів (ASCII Value) помноженого на 0.4.
    vector<int> ASCII_values;
    for (char c : SortedName){
        ASCII_values.push_back(static_cast<int>(c) * 0.4);
    } 

    vector<int> selectedNumbers = (ASCII_values.begin() + 1, ASCII_values.end() + 4);
    vector<vector<float>> matrix = (5, vector<float>(3, 0));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            if (j < selectedNumbers.size()){
                matrix[i][j] = static_cast<float>(selectedNumbers[j]);
            }
        }
    }

    vector<vector<float>> result(5, vector<float>(3, 0));

}

int main (){

    string userName;
    cout << "Enter your name: ";
    cin >> userName;

    return 0;
}