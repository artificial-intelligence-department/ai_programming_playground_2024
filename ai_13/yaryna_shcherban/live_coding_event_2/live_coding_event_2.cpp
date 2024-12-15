#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;
// 4) константи
const double mile = 1609.344;
const double us_mile = 1609.347;
const double meter = 1.0;

bool isPalindrome(double number) {
    string numStr = to_string(static_cast<long long>(number));
    int len = numStr.length();

    for (int i = 0; i < len / 2; i++) {
        if ( numStr[i] != numStr[len - 1 - i]){
            return false;
        }
    }
    return true;
}

double simulateMoneyPrecision(double value) {
// 15) математичні операції та математичні функції
    return round(value * 100.0) / 100.0;
}
// 14) параметри та аргументи функції
void sortName(const char name[], int sortedName[], int length) {
// 10) for цикл
    for (int i = 0; i < length; i++) {
        sortedName[i] = static_cast<int>(name[i]);
    }
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (sortedName[j] > sortedName[j + 1]) {
                int temp = sortedName[j];
                sortedName[j] = sortedName[j + 1];
                sortedName[j + 1] = temp;
            }
        }
    }
}
// 20) вказівники
void saveToFile(const char* filename, double* userID, double finalCost,  int size) {
// 16) функції роботи з файлами, для того, щоб записати у файл
    ofstream file(filename);
    if (!file) {
        cerr << " Error creating file! " << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        file << fixed << setprecision(1) << userID[i] << endl;
    }
    cout << fixed << setprecision(2) << finalCost << endl;
    file.close();
    cout << " Saved to file " << endl;
}

int main() {

    char name[] = "Yaryna";
    int nameLength = strlen(name);
// 6) одновимірний масив
    int sortedName[20];
    double userID[20];

    sortName(name, sortedName, nameLength);
    for (int i = 0; i < nameLength; i++) {
        userID[i] = sortedName[i] * 0.4;
    }

    cout << " Your ID : " ;
    for (int i = 0; i < nameLength; i++) {
        cout << fixed << setprecision(1) << userID[i] << " ";
    }
    cout << endl;

    double totalDistance;
    cout << "Enter your total distance (in meters): " << endl;
    cin >> totalDistance;

    double distance;
    char unit;
    cout << "Enter distance and units of measurement ( meter, mile, us_mile ) : ";
    cin >> distance >> unit;
    if (cin.fail()) {
        cout << "Something went wrong!" ;
        return 1;
    }
// 5) умовні оператори та розгалуження    
    if ( unit == mile ) {
        distance = distance * mile;
    } else if ( unit == us_mile ) {
        distance = distance * us_mile;
    }

    totalDistance += distance;
    if (isPalindrome(distance)) {
        totalDistance += 200000;
    }
// 1) цілочисельна змінна
    int bonus = static_cast<int>(totalDistance / 100000);
// 3) одна дійсний з подвійною точністю змінна
    double cost = 100.0;
    double finalCost = cost;
    string useBonus;
    cout << " Your bonuses : " << bonus << "$, Use them? (enter yes or no )" ;
    cin >> useBonus;

    if ( useBonus == "yes" ) {
        int maxBonus = min(bonus, static_cast<int>(finalCost));
        finalCost -= maxBonus;
        distance -= maxBonus * 100000;
    }

    finalCost = simulateMoneyPrecision(finalCost);

    cout << fixed << setprecision(2);
// 18) оператори виведення та введення даних
    cout << " Remaining distance (in km)" << (totalDistance - distance) / 1000 << endl;
    cout << " Final shipping cost : " << finalCost << "$" << endl;

    saveToFile("shipping_cost.txt", userID, finalCost, nameLength );

    return 0;
}