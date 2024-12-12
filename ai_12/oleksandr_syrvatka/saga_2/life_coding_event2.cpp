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
#include <cstring>
#include <fstream>

using namespace std;

const double mi_to_meters = 1609.344;
const double mi_US_to_meters = 1609.347;

bool isPalindrome (int distance){
    string dist = to_string(distance);
    int len = dist.size();
    for(int i = 0; i < len/2; i++){
        if(dist[i] != dist[len - i - 1]){
            return false;
        }
    }
    return true;

}

double convertToMeters(int distance, char measurementSystem[]){
    if (strcmp(measurementSystem,"mi") == 0){
        return distance * mi_to_meters;
    }
    if(strcmp(measurementSystem,"mi_US") == 0){
        return distance * mi_US_to_meters;
    }
}

void bubblesort(string name){
    int n = name.size();
    for (int i = 0; i < n-1; i++ ){
        for (int j = 0; j < n-i-1; j++){
            if (name[j] > name[j+1]){
                swap(name[j], name[j+1]);
            }
        }
    }
}

void fileinsert(string filename, double value){
    ofstream file(filename);
    file << value;
    file.close();
}

double* ASCII(string userName){
    double* ASCIIarray= new double[userName.size()];

    for (int i = 0; i < userName.size(); i++){
        ASCIIarray[i] = static_cast<int>(userName[i])*0.4;
    }
    return ASCIIarray;
}



int main(){

    string userName, measurementSystem;
    int distance;
    cout << "Введіть ваше ім'я: ";
    getline(cin, userName);

    cout << "Введіть відстань: ";
    cin >> distance;

    cout << "Введіть одиницю виміру (meter/mi/mi_US): ";
    getline(cin,measurementSystem);


    int lenght = measurementSystem.size();
    char* charArray = new char[lenght];
    for (int i = 0 ; i< lenght; i++){
        charArray[i] = measurementSystem[i];
    }
    convertToMeters(distance, charArray);

    string price_per_meter = "price_per_meter.txt", price_per_mile = "price_per_mile.txt", price_per_mile_us = "price_per_mile_us.txt" ;
    double price_meter = 0.0005, price_mile = 0.8, price_mile_US = 1.2;

    fileinsert(price_per_meter,price_meter);
    fileinsert(price_per_mile, price_mile);
    fileinsert(price_per_mile_us, price_mile_US);

    double* ID = ASCII;
}