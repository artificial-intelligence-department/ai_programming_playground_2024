#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std; 
    // функція для перевірки, чи є число палідром
bool isPalidrome(int num) {
    string s = to_string(num); // перетворення числа на строку
    int n = s.length();
    for (int i = 0; i < n / 2; ++i){ 
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }

    return true; 
}

int main() {
    string name; 
    int dist; 
    string unit;
    char useBonus;

    // введення даних
    cout << "Введіть ваше ім'я: ";
    cin >> name; 

    cout << "Введіть відстань:";
    cin >> dist;

    cout << "Введіть одиницю виимірювання (mater/mile/mile_us):";
    cin >> unit;

    cout << "Бажаєте ввести бонус у відстань (y/n)?";
    cin >> useBonus;

    // конвертація в метри
    int distM = dist;
    if (unit == "mile") {
        distM = static_cast<int>(dist * 1609.344);
    } else if (unit == "mile_us") {
        distM = static_cast<int>(dist * 1609.347);
    }

    // доаємо бонуси, якщо це палідром
    if (isPalidrome(dist)){
        dist +- 200000; // 200 км в метрах
    }

    // знижка 
    int discount = distM / 100000; 

    // вартість доставки
    double pricePerM = 0.01; // ціна за метр
    double price = distM * pricePerM; 

    // використання бонусів
    if (useBonus == 'y'|| useBonus == 'Y'){
        distM -= discount * 100000; // віднімемо бонуси
        price = distM * pricePerM; // перераховуємо вартість
    }
}