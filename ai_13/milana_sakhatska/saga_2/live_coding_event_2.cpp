#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// Функція для перевірки, чи є число паліндромом
bool isPalindrome(int num) {
    string s = to_string(num); // Перетворення числа у строку
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false; // Якщо символи не збігаються, це не паліндром
        }
    }
    return true; // Якщо всі символи збігаються
}

int main() {
    string name;
    int dist;
    string unit;
    char useBonus;

    // Введення даних
    cout << "Введіть ваше ім'я: ";
    cin >> name;

    cout << "Введіть відстань: ";
    cin >> dist;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> unit;

    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> useBonus;

    // Конвертація в метри
    int distM = dist;
    if (unit == "mile") {
        distM = static_cast<int>(dist * 1609.344);
    } else if (unit == "mile_us") {
        distM = static_cast<int>(dist * 1609.347);
    }

    // Додаємо бонуси, якщо це паліндром
    if (isPalindrome(dist)) {
        distM += 200000; // +200 км у метрах
    }

    // Обчислюємо знижку
    int discount = distM / 100000; // 1$ кожні 100 км

    // Вартість доставки
    double pricePerM = 0.01; // Ціна за метр
    double price = distM * pricePerM;

    // Використання бонусів
    if (useBonus == 'y' || useBonus == 'Y') {
        distM -= discount * 100000; // Віднімаємо бонуси
        price = distM * pricePerM;  // Перераховуємо вартість
    }

    double distKm = distM / 1000.0; // Переводимо у км

    // Вивід результатів у консоль
    cout << "Відстань поточної доставки: " << distM << "m" << endl;
    cout << "Ваша знижка: " << discount << "$" << endl;
    cout << "Накопичена відстань: " << fixed << setprecision(2) << distKm << "km" << endl;
    cout << "Вартість відправки: " << fixed << setprecision(2) << price << "$" << endl;

    // Запис результатів у файл
    ofstream file("delivery_results.txt");
    if (file.is_open()) {
        file << "Ім'я користувача: " << name << endl;
        file << "Відстань поточної доставки: " << distM << "m" << endl;
        file << "Ваша знижка: " << discount << "$" << endl;
        file << "Накопичена відстань: " << fixed << setprecision(2) << distKm << "km" << endl;
        file << "Вартість відправки: " << fixed << setprecision(2) << price << "$" << endl;
        file.close();
        cout << "Результати збережено у файл 'delivery_results.txt'" << endl;
    } else {
        cout << "Не вдалося відкрити файл для запису." << endl;
    }

    return 0;
}