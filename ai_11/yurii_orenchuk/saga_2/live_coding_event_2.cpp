#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

const int m = 1;
const double mi = 1609.344;
const double mi_US = 1609.347;

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

int createID(char* name){
    int size = sizeof(name) / sizeof(name[0]);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (name[j] > name[j + 1]) swap(name[j], name[j + 1]);
        }
    }
    
    int number[50];
    for(int i = 0; i < size; i++){
        number[i] = (int) name[i];
    }

    int num = 0;
    for (int i = 0; i < size; i++) {
        num *= 10;
        num += number[i];
    }
    return num;
}

bool isPalindrome(int num) {
    if (num < 0) return false;

    int origin = num;
    int rev = 0;

    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }

    return origin == rev;
}

int main(){
    ofstream me("price_per_meter.txt");
    ofstream mi("price_per_mile.txt");
    ofstream mi_US("price_per_mile_US.txt");
    me << 0.0005;
    mi << 0.8;
    mi_US << 1.2;
    me.close();
    mi.close();
    mi_US.close();
    
    char* userName;
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    int ID = createID(userName);

    int distanceValue;
    bool PalinCheck = isPalindrome(distanceValue);
    cout << "Введіть відстань: ";
    cin >> distanceValue;

    string mSys;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> mSys;
    if(mSys == "meter"){
        
    } else if (mSys == "mile"){
        
    } else if (mSys == "mile_us"){

    }

    char convertBonus;
    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;
    if(convertBonus == 'y'){

    } else if (convertBonus == 'n'){

    }

    return 0;
}