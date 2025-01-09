#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

// цілочисельна константа
const double IMPERIAL_MILE = 1609.344; // в метри
const double US_SURVEY_MILE = 1609.347; // в метри

// для округлення, математична операція
double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}


// сортування, двовимірний масив
string mySort(const string& name) {
    string sortedName = name;

    // цикл for
    for(size_t i = 0; i < sortedName.length() - 1; ++i) {
        for(size_t j = 0; j < sortedName.length() - i - 1; ++j) {
            if(sortedName[j] > sortedName[j + 1]) {
                char temp = sortedName[j];
                sortedName[j] = sortedName[j + 1];
                sortedName[j + 1] = temp;
            }
        }
    }
    return sortedName;
}


double generateUserId(const string& name) {
    string sortedName = mySort(name);

    double userId = 0.0;
    for(char c : sortedName) {
        userId = static_cast<int>(c) * 0.4;
    }
    return userId;
}


// рекурсивно шукаємо паліндром
bool isPalindromeBasic(const string& distStr, int start, int end){
    if(start >= end) return true;
    if(distStr[start] != distStr[end]) return false;
    return isPalindromeBasic(distStr, start + 1, end - 1);
}


// основна функція паліндрому
bool isPalindrome(int distance) {
    string distStr = to_string(distance);
    return isPalindromeBasic(distStr, 0, distStr.length() - 1);
}


// читання з файлу
double readPrice(const string& filename) {
    ifstream file(filename);
    double price = 0.0;

    if(file.is_open()) {
        file >> price;
    } else {
        cerr << "Не вдалось відкрити файл " << filename << endl; 
    }
    file.close();
    return price;
}


double convertToMeters(double distance, const string& unit) {
    if(unit == "mile") {
        return distance * IMPERIAL_MILE;
    } else if(unit == "mile_us") {
        return distance * US_SURVEY_MILE;
    } else if(unit == "meter") {
        return distance;
    } else {
        cerr << "Невідома одиниця виміру." << endl;
        return 0.0;
    }
}


// запис у файл
void writeDistance(const string& userName, double userId, double distanceMeter) {
    ofstream outputFile("collected_distance.txt", ios::app);
    if(outputFile.is_open()) {
        outputFile << static_cast<int>(userId) << " " << static_cast<int>(distanceMeter) << endl; 
    } else {
        cerr << "Помилка запису у файл" << endl;
    }
    outputFile.close();
}

void calculateCost() {
    string userName, measurementSystem;
    double distanceValue;

    // цикл do while
    do {
        cout << "Введіть ваше ім'я: ";
        cin >> userName;

        double userId = generateUserId(userName);
        cout << "Ваш унікальний ідентифікатор: " << static_cast<int>(userId) << endl;

        cout << "Введіть відстань: ";
        cin >> distanceValue;

        cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
        cin >> measurementSystem;

        double pricePerUnit = 0.0;
        if(measurementSystem  == "meter") {
            pricePerUnit = readPrice("price_per_meter.txt");
        } else if(measurementSystem == "mile") {
            pricePerUnit = readPrice("price_per_mile.txt");
        } else if(measurementSystem == "mile_us") {
            pricePerUnit = readPrice("price_per_mile_us.txt");
        } else {
            cerr << "Невідома одиниця виміру" << endl;
            continue;  // continue
        }

        double deliveryDistanceInMeters = convertToMeters(distanceValue, measurementSystem);

        if(isPalindrome(static_cast<int>(distanceValue))) {
            deliveryDistanceInMeters += 200 * 1000;
        }

        double totalPrice = simulateMoneyPrecision(pricePerUnit + distanceValue);

        cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
        cout << "Вартість відправки: " << totalPrice << "$" << endl;

        writeDistance(userName, userId, deliveryDistanceInMeters);

        break;  // break
    } while(false);
}

int main() {
    calculateCost();
    return 0;
}