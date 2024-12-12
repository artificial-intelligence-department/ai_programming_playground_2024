#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

// Константи для конвертації
const double BRITISH_MILE = 1609.344;
const double US_SURVEY_MILE = 1609.347;

// Функція для перевірки, чи є число паліндромом
bool isPalindrome(int number) {
    string s = to_string(number);
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Власна функція для сортування рядка за зростанням
void customSort(string& s) {
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
            }
        }
    }
}

// Функція для створення ідентифікатора користувача
string createUserID(const string& name) {
    // Сортуємо букви імені
    string sortedName = name;
    customSort(sortedName);

    // Перетворюємо на ASCII та множимо на 0.4
    stringstream idStream;
    for (char c : sortedName) {
        int value = static_cast<int>(c) * 0.4;
        idStream << value;
    }

    return idStream.str();
}

// Функція для конвертації відстані в метри
double convertToMeters(double distance, const string& unit) {
    if (unit == "mi") {
        return distance * BRITISH_MILE;
    } else if (unit == "mi_US") {
        return distance * US_SURVEY_MILE;
    } else if (unit == "meter") {
        return distance;
    } else {
        throw runtime_error("Невідома одиниця вимірювання.");
    }
}

// Основна функція
int main() {
    try {
        // Введення імені користувача
        string name;
        cout << "Введіть ваше ім'я: ";
        cin >> name;

        // Створення ідентифікатора
        string userID = createUserID(name);
        cout << "Ваш ідентифікатор користувача: " << userID << endl;

        // Введення відстані та одиниці вимірювання
        double distance;
        string unit;
        cout << "Введіть відстань та одиницю вимірювання (mi, mi_US, meter): ";
        cin.ignore();
        cin >> distance ;
        cin.ignore();
        cin >> unit;

        // Конвертація в метри
        double distanceInMeters = convertToMeters(distance, unit);

        // Перевірка на паліндром і нарахування бонусів
        int distanceKm = static_cast<int>(distanceInMeters / 1000);
        int bonusPoints = 0;
        if (isPalindrome(distanceKm)) {
            bonusPoints += 200;  // +200 км бонусів
        }

        // Розрахунок вартості доставки
        FILE* fileStream = fopen("price_per_meter.txt", "rb");
        double ratePerKm;
        fread(&ratePerKm, sizeof(double), 1, fileStream);
        fclose(fileStream);
        int discount = bonusPoints / 100;  // Кожні 100 км = 1$ знижки
        bonusPoints -= discount * 100;
        double cost = distanceKm * ratePerKm - discount;

        // Виведення результатів
        cout << fixed << setprecision(2);
        cout << "Вартість доставки: $" << cost << endl;
        cout << "Залишок бонусів: " << bonusPoints << " км" << endl;
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}