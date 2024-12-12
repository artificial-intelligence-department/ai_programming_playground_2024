#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double mi = 1609.344;
const double mi_US = 1609.347;
const int m = 1;

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

bool isPalindrome(int val) {
    int n, digit, rev = 0;
    n = val;
    do
     {
         digit = val % 10;
         rev = (rev * 10) + digit;
         val = val / 10;
     } while (val != 0);
     if (n == rev and n > 0) return true;
     else return false;
}

int main() {
    ifstream mFile("price_per_meter.txt");
    if (mFile.fail()){
    ofstream mFile("price_per_meter.txt");
    mFile << 0.0005;
    }
    ifstream miFile("price_per_mile.txt");
    if (miFile.fail()){
    ofstream miFile("price_per_mile.txt");
    miFile << 0.8;
    }
    ifstream miUSFile("price_per_mile_us.txt");
    if (miUSFile.fail()){
    ofstream miUSFile("price_per_mile_us.txt");
    miUSFile << 1.2;
    }
    ofstream miUSFile("price_per_mile_us.txt");
    if (!miFile || !mFile || !miUSFile) {
        cerr << "cant open";
        return;
    }

    cout << "Введіть ваше ім'я: ";
    string userName;
    double distanceValue;
    string measurementSystem;
    char convertBonus;

    cin >> userName;

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;
    int id[100];
    int nameSize = userName.length();
    for(int i = 0; i < nameSize - 1; i++) {
        for(int j = 0; j < nameSize - i - 1; j++) {
            if(userName[j] > userName[j + 1]) {
                swap(userName[j], userName[j + 1]);
            }
        }
    }

    for(int i = 0; i < nameSize; i++) {
        id[i] = userName[i] * 0.4;
    }

    bool needBonus;
    if('y' == convertBonus) {
        needBonus = true;
    } else {
        needBonus = false;
    }

    string pricestr;
    if(measurementSystem.compare("mile")) {
        getline(miFile, pricestr);
        distanceValue = distanceValue * mi;
    } else if (measurementSystem.compare("mile_us")) {
        getline(miUSFile, pricestr);
    }else if (measurementSystem.compare("meter")) {
        getline(mFile, pricestr);
    }

    double price = stod(pricestr);
    ofstream collectedDistance("collected_distamce.txt");
    if(!collectedDistance) return;
    for(int i = 0; i < nameSize; i++){
    collectedDistance << id[i];
    }
    collectedDistance << " ";
    collectedDistance << distanceValue;
    int bonuses = 0;
    if(isPalindrome(distanceValue)) {
        bonuses += 200;
    }
    
}