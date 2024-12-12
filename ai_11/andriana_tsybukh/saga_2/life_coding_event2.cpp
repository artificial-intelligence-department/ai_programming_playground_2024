#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double IMPERIAL_MILE = 1609.344; // в метри
const double US_SURVEY_MILE = 1609.347; // в метри

// для округлення
double simulateMoneyPrecision(double value) {
    return std::round(value * 100.0) / 100.0;
}


// сортування
string mySort(const string& name) {
    string sortedName = name;

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

// перевірка паліндрому
// bool isPalindrome(int distance) {
//     string distStr = to_string(distance);
//     string reversedDistStr = distStr;
//     size_t n = distStr.length();

//     for(size_t i = 0; i < n / 2; ++i) {
//         if(distStr[i] != distStr[n - i - 1]) {                        переписати рекурсивно
//             return false;
//         }
//     }
//     return true;
// }


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

void writeDistance(const string& userName, double userId, double distanceMeter) {
    ofstream outputFile("collected_distance.txt", ios::app);
    if(outputFile.is_open()) {
        outputFile << static_cast<int>(userId) << " " << static_cast<int>(distanceMeter) << endl; 
    } else {
        cerr << "Помилка запису у файл" << endl;
    }
    outputFile.close();
}