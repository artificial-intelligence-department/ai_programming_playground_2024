#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

const double MI_TO_M = 1609.344;
const double MI_US_TO_M = 1609.344;
const double KM_BONUS = 200000;

string reverseString(string str, int start, int end) { 
    while(start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    return str;
}

bool isPalindrom(string distanceValue) {
    
    string rev = reverseString(distanceValue, 0, distanceValue.length() - 1); 
    return distanceValue == rev;
}


double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

int main() {
    string userName;
    cout << "Введіть ваше ім'я: ";
    cin >> userName;

    char charArray[userName.length()];

    for (int i = 0; i < userName.length(); i++) {
        charArray[i] = userName[i];
    }

    for (int i = 0; i < userName.length() - 1; i++) {
            for (int k = 0; k < userName.length() - 1 - i; k++) {
                if (charArray[k] > charArray[k + 1]) {
                    swap(charArray[k], charArray[k + 1]);
                }
            }
        }

    int idArray[userName.length()];

    for (int i = 0; i < userName.length(); i++) {
        idArray[i] = static_cast<int>(userName[i])*0,4;
    }

    double distanceValue;
    cout << "Введіть відстань: ";
    cin >> distanceValue;

    string measurementSystem;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    double disInM;
    if (measurementSystem == "mile") {
        disInM = distanceValue*MI_TO_M;
    }
    else if (measurementSystem == "mile_us") {
        disInM = distanceValue*MI_TO_M;
    }

    if(isPalindrom(to_string(static_cast<int>(distanceValue)))) {
        distanceValue += KM_BONUS;
    }
    
    string convertBonus;
    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;

    for (int i = 0; i < userName.length(); i++) {
        cout << idArray[i];
    }
    cout << "   " << distanceValue;

    double deliveryDistanceInMeters, discount, deliveryDistanceInKiloMeters, totalPrice;

    ofstream MyFile("price_per_meter.txt");
    MyFile << "0.0005";
    MyFile.close();

    ofstream MyFile("price_per_mile.txt");
    MyFile << "0.08";
    MyFile.close();

    ofstream MyFile("price_per_mile_us.txt");
    MyFile << "1.2";
    MyFile.close();

    

    cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
    cout << "Ваша знижка: " << discount << "$" << endl;
    cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
    cout << "Вартість відправки: " << totalPrice << "$" << endl;

    return 0;
}