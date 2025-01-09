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
        number[i] *= 0.4;
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
    ofstream meter_val("price_per_meter.txt");
    ofstream mile_val("price_per_mile.txt");
    ofstream mile_US_val("price_per_mile_US.txt");
    meter_val << 0.0005;
    mile_val << 0.8;
    mile_US_val << 1.2;
    meter_val.close();
    mile_val.close();
    mile_US_val.close();
    
    char* userName;
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    int ID = createID(userName);

    double distanceValue;
    cout << "Введіть відстань: ";
    cin >> distanceValue;
    int bonus = 0;
    if(isPalindrome(distanceValue)){
        bonus += 200;
    }

    string mSys;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> mSys;
    int meterDist;
    if(mSys == "meter"){
        meterDist = distanceValue;
    } else if (mSys == "mile"){
        meterDist = distanceValue * mi;
    } else if (mSys == "mile_us"){
        meterDist = distanceValue * mi_US;
    }

    ofstream userInfo("collected_distance.txt");
    userInfo << ID << " " << meterDist;
    userInfo.close();

    char convertBonus;
    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;
    if(convertBonus == 'y'){
        meterDist += bonus;
        bonus -= 200;
    }

    ifstream last("price_per_meter.txt");
    double temp;
    last >> temp;
    double value = temp * meterDist;
    last.close();

    return 0;
}