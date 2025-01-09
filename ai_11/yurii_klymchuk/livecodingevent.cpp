#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
const double meter = 1.0;
const double mile = 1609.344;
const double mile_us = 1609.347;

bool isPalindrome(int n){
    int reversed = 0;
    int original = n;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return original == reversed;
}

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

int calculateBonus (double distance) {
    distance /= 100;
    int current_bonus = 0;
    while (distance >= 100) {
        distance -= 100;
        current_bonus++;
    }
    return current_bonus;
}

int* UserIdentificator (int n, char v[]) {
    for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (v[j] > v[j + 1])
                    swap(v[j], v[j + 1]);
        }
    }
    
    int* array = new int[n];
    for (size_t i = 0; i < n; i++) {
        // int* array[i] = (int)(round((float)((int)v[i]) * 0.4));
    } 

    return array;
}

double deliveryDistanceInKiloMeters;

double ConvertMeter(int distance) {
    return (double)distance * meter;
}

double ConvertMile(int distance) {
    return (double)distance * mile;
}

double ConvertMile_US(int distance) {
    return (double)distance * mile_us;
}

void OveralDistance (double distance) {
    distance /= 1000;
    deliveryDistanceInKiloMeters += distance;
}

double calculatePrice(double distance, int bonuses) {
    ifstream file ("price_per_meter.txt");
    float price_per_meter;
    file >> price_per_meter;
    file.close();
    double price = distance*price_per_meter - bonuses;
    if (price < 0) {
        price = 0;
    }
    return price;
}

int main () {
    ofstream file_1("price_per_meter.txt");
    file_1 << 0.0005;
    file_1.close();

    ofstream file_2("price_per_mile.txt");
    file_2 << 0.8;
    file_2.close();
    
    ofstream file_3("price_per_mile_us.txt");
    file_3 << 1.2;
    file_3.close();

    int bonus = 0;

    char userName[64];
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    int size = sizeof(userName);
    int* array = UserIdentificator(size, userName);

    int distanceValue;
    cout << "Введіть відстань: ";
    cin >> distanceValue;
    if (isPalindrome(distanceValue)) {
        bonus += calculateBonus(200);
    }

    double deliveryDistanceInMeters = 0;
    string measurementSystem;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;
    if (measurementSystem == "meter") {
        deliveryDistanceInMeters = ConvertMeter(distanceValue);
    } else if (measurementSystem == "mile") {
        deliveryDistanceInMeters = ConvertMile(distanceValue);
    } else if (measurementSystem == "mile_us") {
        deliveryDistanceInMeters = ConvertMile_US(distanceValue);
    }



    char convertBonus;
    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;
    if (convertBonus == 'Y' || convertBonus == 'y') {
        bonus += calculateBonus(deliveryDistanceInMeters);
    } else if (convertBonus == 'N' || convertBonus == 'n') {
        OveralDistance(deliveryDistanceInMeters);
    }

    double totalPrice = calculatePrice(deliveryDistanceInMeters, bonus);
    cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
    cout << "Ваша знижка: " << bonus << "$" << endl;
    cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
    cout << "Вартість відправки: " << totalPrice << "$" << endl;
    return 0;
}