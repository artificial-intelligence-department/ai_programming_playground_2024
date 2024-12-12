#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

void price_files(){
    ofstream f1("price_per_meter.txt");
    f1 << 0.0005;
    f1.close();

    ofstream f2("price_per_mile.txt");
    f2 << 0.8;
    f2.close();

    ofstream f3("price_per_mile_us.txt");
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

int* convertToAscii(string name){
    int n = name.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(name[j] > name[j+1]){
                swap(name[j],name[j+1]);
            }
        }
    }

    int* arr = new int;
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
    ofstream f("collected_distance.txt", ios::app);
    int size = sizeof(asc) / sizeof(asc[0]);
    int number = 0;
    for (int i=0; i<size; i++){
        f << asc[i];
    }
    f << " " << dist << endl;
    f.close();
}

// void bonuses(int* asc, int dist){
//     ifstream f("collected_distance.txt");
//     stringstream ss;
//     int num;
//     int ascii = 0;
//     for(int i=0; i<sizeof(asc) / sizeof(asc[0]); i++){
//         ss << asc[i];
//     }
//     ss >> ascii;

//     while(f >> num){
//         if(ascii==num){
            
//         }
//     }
// }

double calculate_price(int distanceValue){
    ifstream f("price_per_meter.txt");
    double num;
    f >> num;
    f.close();
    return distanceValue*num;
}

int main(){
    string name;
    int distanceValue;
    string measurementSystem;
    price_files();

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

    int* asc = convertToAscii(name);

    // if(isPalindrome(distanceValue)){
    //     distanceValue+=200;
    // }

    write_to_file(asc, distanceValue);
    cout << "Відстань поточної доставки: " << " " << distanceValue << "m" << endl;


    cout << "Вартість відправки: " << " " << calculate_price(distanceValue) << "$" << endl;;



    return 0;
}
