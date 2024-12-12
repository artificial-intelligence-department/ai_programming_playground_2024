#include<iostream>
//#include <vector>
#include <climits>

#include <random>
#include <fstream>

using namespace std;
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
// ім'я, відстань, (meter/mile/mile_us);
struct User{
    string name;
    double distance;
    string value;
    double distance_for_sale = 0;
};

double get_price(string file){
    double result;
    ifstream File(file);
   if (!File.is_open()) {
        exit(1);
    }
    File >> result;
    return result;
}

const string users_file = "Users_file.txt";
const double meter_price = get_price("price_per_meter.txt");
const double mile_price = get_price("price_per_mile.txt");
const double mile_us_price = get_price("price_per_mile_us.txt");




double simulateMoneyPrecision(double value) {
    return std::round(value * 100.0) / 100.0;
}
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true; 
    }
    if (str[start] != str[end]) {
        return false; 
    }
    return isPalindrome(str, start + 1, end - 1);
}
bool isPalindrome(int num) {
    if (num < 0){return false;}

    int reversed = 0, original = num;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

double To_meters(double value, string m){
    if(m == "mile"){
        return value*mile_price;
    }
    else if(m == "mile_us"){
        return value*mile_us_price;
    }
    return 0;
}

void bubbleSort(string& arr) {
    int n = arr.length();
    bool swapped;
    int temp;
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}


int main(){
    User Alex;

    cout << "Введіть ваше ім'я: ";
    cin >> Alex.name;

    cout << "Введіть відстань: ";
    cin >> Alex.distance;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> Alex.value;

    double Alex_id[Alex.name.length()];
    string temp = Alex.name;
    for(int i = 0; i<Alex.name.length(); i++){
        Alex_id[i] = temp[i];
    }

    if(isPalindrome(static_cast<int>(Alex.distance))){
        Alex.distance_for_sale += 200;
    }
    std::ofstream file(users_file, std::ios::app);
    file << Alex.name <<" "<< Alex.distance <<" in "<< Alex.value<< " " <<Alex.distance_for_sale;
    for(int i = 0; i<Alex.name.length(); i++){
        file << Alex_id[i];
    }
    file << "\n";

    file.close();

    return 0;
}