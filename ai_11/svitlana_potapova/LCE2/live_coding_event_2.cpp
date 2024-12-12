#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

void price_files(){
    fstream f1("price_per_meter.txt");
    f1 << 0.0005;
    f1.close();

    fstream f2("price_per_mile.txt");
    f2 << 0.8;
    f2.close();

    fstream f3("price_per_mile_us.txt");
    f3 << 1.2;
    f3.close();
}

int milesToMetres(double mi){
    return mi * 1609.344;
}

int usmilesToMetres(double mi_us){
    return mi_us * 1609.347;
}

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

int* idenf(string name){
    int n = name.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(name[j] > name[j+1]){
                swap(name[j],name[j+1]);
            }
        }
    }

    int* arr = new int[n];
    for(int i=0; i<n; i++){
        char c = name[i];
        int ascii = static_cast<int>(c);
        arr[i] = ascii * 0.4;
    }
    return arr;
}

bool isPalindrome(int num){
    int reverse = 0, digit;
    int temp = num;
    while(temp!=0){
        digit = temp%10;
        reverse = reverse*10 + digit;
        temp /= 10; 
    }

    if(num==reverse){
        return true;
    }
    else{
        return false;
    }
}

void write_to_file(int* asc, int dist){
    fstream f("collected_distance.txt", ios::app);
}

int main(){
    string name;
    int distanceValue;
    string measurementSystem;


    cout << "Введіть ваше ім'я: ";
    cin >> name;
    cout << "Введіть відстань: ";
    cin >> distanceValue; 
    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    if(measurementSystem == "mile"){
        distanceValue = milesToMetres(distanceValue);
    }
    else if(measurementSystem == "mile_us"){
        distanceValue = usmilesToMetres(distanceValue);
    }

    int* asc = idenf(name);





    return 0;
}
