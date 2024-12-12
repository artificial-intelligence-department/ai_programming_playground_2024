#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

const int meter = 1; //цілочисельна константа
const double mile = 1 609.344; //дійсний з подвійною точністю змінна
const double mile_us = 1609.347; 

bool isPalyndrome(double number){
    string str = to_string(number);
    int n = str.size();
    for(int i = 0; i < n / 2 i++){ // for цикл
        if(str[i] != str[n - i - 1]){
            return false;
        }
    }
    return true;
}

void bubbleSort(char* str, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(str[j] > str[j +1])
            char temp = str[j];
            str[j] = str[j+1];
            str[j+1] = temp;
        }
    }
}

double readFromFile(const string& fileName){
    ifstream file(fileName);
    if(!file){
        cerr << "Помилка: не вдалося відкрити файл" << endl;
        return 0;
    }
    double price;
    file >> price;
    file.close();
    return price;
}

void createFiles(){
    ofstream file;
    file.open("price_per_meter.txt");
    if(file){
        file << 0.0005;
        file.close();
    }else{
        cerr << "Помилка: не вдалося відкрити файл" << endl;
    }
    file.open("price_per_mile.txt");
    if(file){
        file << 0.8;
        file.close();
    }else{
        cerr << "Помилка: не вдалося відкрити файл" << endl;
    }
    file.open("price_per_mile_us.txt");
    if(file){
        file << 1.2;
        file.close();
    }else{
        cerr << "Помилка: не вдалося відкрити файл" << endl;
    }
}



int main(){
    createFiles();
    string userName;
    double distanceValue;
    string measurementSystem;

    double pricePerMeter = readFromFile("price_per_meter.txt");
    double pricePerMile = readFromFile("price_per_mile.txt");
    double pricePerMileUs = readFromFile("price_per_mile_us.txt");

    cout << "Введіть ваше ім'я: ";
    cin >> userName;

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    if(measurementSystem == 'meter'){
        float price = pricePerMeter * distanceValue;
    }else if(measurementSystem == 'mile'){
        float price = pricePerMile * distanceValue;
    }else{
        float price = pricePerMileUs * distanceValue;
    }

    cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
    cout << "Ваша знижка: " << discount << "$" << endl;
    cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
    cout << "Вартість відправки: " << totalPrice << "$" << endl;


    double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

    return 0;
}