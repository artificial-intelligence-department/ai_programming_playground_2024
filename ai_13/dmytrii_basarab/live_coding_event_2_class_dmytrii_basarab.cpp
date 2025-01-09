#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double mi = 1609.344;
const double mi_Us = 1609.347;
  
bool isPalindrome(int num) {
    if (num < 0) { 
        return false;
    }
int a = num;
int reversed = 0;
while (num > 0) {
int digit = num % 10;//з 121 дає 1 останню
num = num / 10;// зі 121 робить 12
reversed = reversed * 10 + digit;//перше після цього реверс робиться 1 потім 10 плюс наступний дігіт (2) і тд
}
return reversed == a;  //порівнює і дає тру чи фолс 
}

const double price_per_meter = 0.0005;

const double price_per_mile = 0.8;

const double price_per_mile_us = 1.2;



int main(){
string userName;
double distanceValue;
int measurementSystem;
vector<int> id;
double bonuses_km;
double price;

cout << "Введіть ваше ім'я: ";
cin >> userName;

 cout << "Введіть відстань: ";
 cin >> distanceValue;
    if (distanceValue < 0) {
        return 0;
    }

  cout << "Введіть одиницю виміру (1)meter  (2)mile  (3)mile_us: ";
  cin >> measurementSystem;


    string sorted_name;
    sorted_name = userName;
    
    sort(sorted_name.begin(), sorted_name.end());
    for (int i = 0; i<sorted_name.length() - 1;i++) {
        id.push_back(int(sorted_name[i])*0.4);
    }




    switch (measurementSystem) {
        case 1: 
        price = distanceValue*price_per_meter;
        bonuses_km += distanceValue/1000;

        break;
        case 2: 
        price = distanceValue*price_per_mile;
        bonuses_km += distanceValue/mi/1000;
        break;
        case 3: 
        price = distanceValue*price_per_mile_us;
        bonuses_km += distanceValue/mi_Us/1000;
        break;
        default:
        cout << "Неправильне число";
        return 0;
    }

    if (isPalindrome(static_cast<int>(distanceValue))) {
        cout << "Дано бонуси 200 км!" << endl;
        bonuses_km += 200; 
    }
    cout << endl;

    cout << "Ціна до бонусів: "<< price << endl;
    char answer;
        cout << "Ти маєш " << static_cast<int>(bonuses_km)/100 << " долари(-ів) бонусів." << endl;
        cout << "Використати їх?(y/n)";
        cin >> answer;
        if (answer = 'y') {
            cout << "Знижка" << static_cast<int>(bonuses_km)/100 << endl;            
            price -= static_cast<int>(bonuses_km)/100;
            bonuses_km -= (static_cast<int>(bonuses_km)/100)*100;
            cout << "Ціна після бонусів: "<< price;
        } else {
            cout << "Ціна без бонусів: "<< price;   
        }


    ofstream file;
    file.open("userdata.txt", ios::out);
    file << "Username: " << userName;
    file << endl;
    file << "ID: ";
    for (int i = 0; i < id.size() - 1; i++) {
    file << id[i];
    }
    file << endl;
    file << "Bonuses: " << bonuses_km;
    file.close();

    return 0;
}