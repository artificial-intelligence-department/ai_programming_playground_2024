#include <iostream>
#include <iomanip> 
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double Imperial_mile = 1609.344;
const double US_survey_mile = 1609.347;


// в коді використана як мінімум одна цілочисельна змінна
// в коді використана як мінімум одна дійсна змінна
// в коді використана як мінімум одна дійсний з подвійною точністю змінна
// в коді використана як мінімум одна цілочисельна константа
// в коді використані умовні оператори та розгалуження
// в коді використаний одновимірний масив 
// в коді використаний двовимірний масив 
// в коді використаний do while цикл
// в коді використаний while цикл
// в коді використаний for цикл 
// в коді використано оператори break і continue
// в коді використано перевантаження функції 
// в коді використано рекурсивну функцію 
// в коді використано параметри та аргументи функції	
// в коді використано математичні операції та математичні функції
// в коді використано функції роботи з файлами, для того, щоб записати у файл
// в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
// в коді використано оператори виведення та введення даних
// в коді використано свою структуру даних
// в коді використано вказівники

void bubblesort(string &name){
    int n = name.length();
    string Sorted_name = name;

for(int i = 0; i<n - 1;i++){
    for(int j = 0;j<n;j++){
        if(Sorted_name[j]>Sorted_name[j + 1]){
            swap(Sorted_name[j], Sorted_name[j+1]);
        }
    }
}

for(int i = 0;i<n; i++){
    cout<<Sorted_name[i]<<" ";
}
}

bool isPalindrome(int distance){
    string str = to_string(distance);
    string reverse = string(str.begin(), str.end());
    return str == reverse;
}

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

double getPrice(const string& filename){
ifstream file(filename);
if(!file.is_open()){
    cout<<"Не вдалось відкрити файл"<<endl;
}
double price;
file >>price;
file.close();
return price;
}


class Delivery{
private:
    string userName;
    double totaldist;

public:
    Delivery(const string& name) : userName(name), totaldist(0) {
        bubblesort(name);
    }

void addDistance(double distanceKm, const string& unit){
    double distanceMeter;
    if(unit == "mile"){
        distanceKm = distanceKm*Imperial_mile;
    }else if(unit == "mile_us"){
        distanceKm = distanceKm*US_survey_mile;
    }else if(unit == "meter"){
        distanceKm = distanceKm;    
    }else{
        cout<<"Невідома одиниця виміру"<<endl;
    }

double distanceInKm = distanceMeter / 1000;
if(isPalindrome(distanceKm)){
    totaldist +=distanceKm;
}
}
double CalculateDiscount(){
    return floor(totaldist / 100);
}
double getTotalKm(){
    return totaldist;
}
void SaveToFile(){
    ofstream outFile(userName + "_collected_distance.txt");
    if(outFile.is_open()){
        double discount = simulateMoneyPrecision(CalculateDiscount());
        out.File<<fixed<<setprecision(2)<<totaldist<<"\t"<<discount;
        outFile.close()
    }else{
        cout<<"Не вдалось відкрити файл"<<endl;
    }
}

double CalculateCost(const string& unit){
    double pricePerUnit;
    if(unit == "meter"){
        pricePerUnit = getPrice("price_per_meter.txt")
    }else if(unit == "mile"){
        pricePerUnit = getPrice("price_per_mile.txt")
    }else if(unit == "mile_us"){
        pricePerUnit = getPrice("price_per_mile_us.txt")
    }else {
        cout<<"Виникла помилка"<<endl;
    }
    double totalDistanceInMeter = totaldist * 1000;
    return totalDistanceInMeter;
}
};


int main(){
string userName;
double distanceValue;
string measurementSystem;
string convertBonus;

cout << "Введіть ваше ім'я: ";
cin >> userName;

cout << "Введіть відстань: ";
cin >> distanceValue;

cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
cin >> measurementSystem;

cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
cin >> convertBonus;
if(convertBonus == "y"){
    double discount = simulateMoneyPrecision(Delivery.CalculateDiscount());
    cout << "Ваша знижка: " << discount << "$" << endl;
}

cout << "Відстань поточної доставки: " <<  << "m" << endl;
cout << "Накопичена відстань: " <<  << "km" << endl;
cout << "Вартість відправки: " << CalculateCost() << "$" << endl;

Delivery.saveToFile();
cout<<"Дані успішно збережені"<<userName<<"_collected_distance.txt"<<endl;
return 0;
}

