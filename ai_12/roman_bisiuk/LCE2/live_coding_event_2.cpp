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

bool isPalyndrome(double number){ // параметри та аргументи функції	
    string str = to_string(number);
    int n = str.size();
    for(int i = 0; i < n / 2 i++){ // for цикл
        if(str[i] != str[n - i - 1]){
            return false;
        }
    }
    return true;
}

void bubbleSort(char* str, int n){ //використано вказівники
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(str[j] > str[j +1])
            char temp = str[j];
            str[j] = str[j+1];
            str[j+1] = temp;
        }
    }
}

void gemerateUserId(contst string& name){ // параметри та аргументи функції
    int n = name.size();
    char sortedName[n]; //одновимірний масив 
    for(int i = 0; i < n; i++){
        sortedName[i] = name[i];
    }

    bubbleSort(sortedName, n);
    for(int i = 1; i <= n; i++){
    int value = static_cast<int>(sortedName[i]) * 0.4;
    cout << value " ";
    }
    cout << endl;
}

double readFromFile(const string& fileName){ 
    ifstream file(fileName); //функції роботи з файлами, для того, щоб зчитати з файлу
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
        file << 0.0005; // функції роботи з файлами, для того, щоб записати у файл
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
    int discount; // цілочисельна змінна

    double pricePerMeter = readFromFile("price_per_meter.txt");
    double pricePerMile = readFromFile("price_per_mile.txt");
    double pricePerMileUs = readFromFile("price_per_mile_us.txt");

    cout << "Введіть ваше ім'я: ";
    cin >> userName; // оператори виведення та введення даних

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    float price;
    if(measurementSystem == 'meter'){
        price = pricePerMeter * distanceValue;
    }else if(measurementSystem == 'mile'){
        price = pricePerMile * distanceValue;
    }else{
        price = pricePerMileUs * distanceValue; // дійсна змінна
    }
    int deliveryDistanceInMeters;
    int deliveryDistanceInKiloMeters;
    if(measurementSystem = 'mile'){
        deliveryDistanceInMeters = mile_us * meter;
        deliveryDistanceInKiloMeters = deliveryDistanceInMeters / 1000;
    }
    if(measurementSystem = 'mile_us'){
        deliveryDistanceInMeters = mile_us * meter;
        deliveryDistanceInKiloMeters = deliveryDistanceInMeters / 1000;
    }
    float totalPrice = price - discount;

    cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
    cout << "Ваша знижка: " << discount << "$" << endl;
    cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
    cout << "Вартість відправки: " << totalPrice << "$" << endl;


    double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

    return 0;
}