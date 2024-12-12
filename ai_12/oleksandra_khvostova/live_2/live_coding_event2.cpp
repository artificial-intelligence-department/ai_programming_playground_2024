#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;

struct Distance{
    int distance_meters;
    double dastance_miles;
    double distance_miles_us;
};

long long bonus = 0;

int* Identifier(string name){
    string sorted = name;
    int* identifier = new int[sorted.size()];
    sort(sorted.begin(), sorted.end());
    for(int i=0; i<sorted.size(); ++i){
        identifier[i] = static_cast<int>(sorted[i+1])*0.4;
    }
    ofstream outFile("students.txt");
    outFile << name <<" "<<endl;
    outFile.close();
    return identifier;
}

int distanceInMeters(double value){
    
}

double distanceInMeters(Distance distance);

bool isPalindrome(long long num) {
    if (num < 0) {
        return false; // Від'ємні числа не можуть бути паліндромами
    }
    if (num == 0) {
        return true; // Нуль є паліндромом
    }
    int reversedNum = 0;
    int originalNum = num;
    while (num != 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }
    return originalNum == reversedNum;
}

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

long long bonusCount(long long distance){
    long long discount = 0;
    if(isPalindrom(distance)){
        bonus+=200000;
    }
    discount += bonus/100000;
    return discount;
}

double identifyPrice(string num){
    if(num=="meter"){
        ifstream inFile("price_per_meter.txt");
        string line;
        while (getline(inFile, line)) {
        double price_m = line.stod(line);
        }
        inFile.close();}
    if(num=="mile"){
        ifstream inFile("price_per_mile.txt");
        string line;
        while (getline(inFile, line)) {
        double price_m = line.stod(line);
        }
        inFile.close();}
    if(num=="mile_us"){
        ifstream inFile("price_per_mile.txt");
        string line;
        while (getline(inFile, line)) {
        double price_m = line.stod(line);
        }
        inFile.close();
    }
}

int main(){
    string userName;
    int distanceValue;
    string measurementSystem;
    char convertBonus;
    long long discount = bonusCount();
    int* identifier = Identifier(name);
    cout << "Введіть ваше ім'я: ";
    cin >> userName;

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;

    cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
    cout << "Ваша знижка: " << discount << "$" << endl;
    cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
    cout << "Вартість відправки: " << totalPrice << "$" << endl;

    delete[]identifier;
    return 0;
}