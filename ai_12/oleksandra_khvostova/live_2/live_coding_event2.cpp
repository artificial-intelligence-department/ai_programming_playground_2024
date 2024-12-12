#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Distance{
    double distance;
    int identifier[15];
};

long long bonus = 0;

int* Identifier(string name){
    string sorted = name;
    int* identifier = new int[sorted.size()];
    sort(sorted.begin(), sorted.end());
    for(int i=0; i<sorted.size(); ++i){
        identifier[i] = static_cast<int>(sorted[i+1])*0.4;
    }
    ofstream outFile("id.txt");
    outFile << name <<" "<<endl;
    for(int i=0; i<sorted.size(); i++){
        outFile<<identifier[i];
    }
    outFile<<endl;
    outFile.close();
    return identifier;
}

double distanceInMeters(double value, string num){
    double val;
    if(num=="meter"){
            val=value;
        }
    if(num=="mile"){
            val=value*1609.344;
        }
    if(num=="mile_us"){
            val=value*1609.347;        
    }
    return val;
}

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

double bonusCount(double distance){
    long long discount = 0;
    if(isPalindrome(distance)){
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
        double price_m = atof(line.c_str());
        }
        inFile.close();}
    else if(num=="mile"){
        ifstream inFile("price_per_mile.txt");
        string line;
        while (getline(inFile, line)) {
        double price_m = atof(line.c_str());
        }
        inFile.close();}
    else if(num=="mile_us"){
        ifstream inFile("price_per_mile.txt");
        string line;
        while (getline(inFile, line)) {
        double price_m = atof(line.c_str());
        }
        inFile.close();
    }
}

int main(){
    string userName;
    int distanceValue;
    string measurementSystem;
    char convertBonus;
    string meter = "meter";

    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    int* identifier = Identifier(userName);

    cout << "Введіть відстань: ";
    cin >> distanceValue;
    long long discount = bonusCount(distanceValue);

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    double deliveryDistanceInMeters = distanceInMeters(distanceValue, measurementSystem);

    while(true){
        cout<<"Menu:"<<endl;
        cout<<"1. Накопичена відстань"<<endl;
        cout<<"2. Вартість відправки"<<endl;
        cout<<"3. Скористатися знижкою"<<endl;
        cout<<"4. Вийти з меню"<<endl;

        int choice;
        cin>>choice;

        if(choice == 1){
            cout<<"Накопичена відстань: "<<bonus<<" m"<<endl;
        }

        if(choice == 2){
            cout << "Вартість відправки: " << identifyPrice(meter)*deliveryDistanceInMeters - discount << "$" << endl;
        }

        if(choice == 3){
            discount = bonusCount(deliveryDistanceInMeters);
            cout << "Ваша знижка: " << discount << "$" << endl;
            cout << "Вартість відправки: " << identifyPrice("meter")*deliveryDistanceInMeters - discount << "$" << endl;
        }

        if(choice == 4){
            cout<<"Гарного дня!";
            break;
        }
    }

    delete[]identifier;
    return 0;
}