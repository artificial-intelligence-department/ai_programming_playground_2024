#include <iostream>
#include <sstream>
#include <string>
#include <iomanip> 
#include <cmath>
using namespace std;

const double imperial_miles_to_meters = 1609.344;
const double us_miles_to_meters = 1609.347;
const double metric_to_meters = 1.0;

bool isPalindrome(int number) {
    string numStr = to_string(number);
    string reversedStr = numStr;
    reverse(reversedStr.begin(), reversedStr.end());
    return numStr == reversedStr;
}

string generateUserID(const string name) {
    string sortedName = name;
    for(size_t i=0;i<sortedName.length()-1;i++) {
        for(size_t j=0;j<sortedName.length()-1-i;j++) {
            if(sortedName[j]>sortedName[j+1]) {
                swap(sortedName[j], sortedName[j+1]);
            }
        }
    }
    ostringstream userID;
    for(char a: sortedName) {
        int ASCII_value = static_cast<int>(a);
        int Modified_value = static_cast<int>(ASCII_value*0.4);
        userID<<Modified_value;
    }
    return userID.str();
}

int main() {
    string userName;
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    string measurementSystem;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;
    double system_conversion;
    if (measurementSystem =="mile") {
        measurementSystem = imperial_miles_to_meters;
    } else if(measurementSystem=="mile_us") {
        measurementSystem = us_miles_to_meters;
    } else if(measurementSystem == "meter") {
        measurementSystem = metric_to_meters;
    } else {
        cout<<"Система вимірювання введена невірно"<<endl;
        return 1;
    }
    double distanceValue;
    cout << "Введіть відстань: ";
    cin >> distanceValue;
    double distanceInMeters = system_conversion*distanceValue;
    cout<<"Відстань у метрах"<<fixed<<setprecision(2)<<distanceInMeters<<"m"<<endl;

    if(isPalindrome(static_cast<int>(distanceValue))) {
        cout<<"Бонус +200км"<<endl;
        distanceInMeters +=200*system_conversion;
    }
    double discount = floor(distanceInMeters/100000)*1.0;
    cout<<"Знижка:"<<discount<<endl;
    cout<<"Кінцева відстань з урахуванням бонусів:"<<distanceInMeters<<"m"<<endl;
    return 0;
}