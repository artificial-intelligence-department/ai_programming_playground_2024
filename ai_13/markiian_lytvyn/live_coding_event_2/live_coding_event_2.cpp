#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double meter = 1;
const double mile = 1609.344;
const double mile_us = 1609.347;

bool palindrome(int distance){
    int uno=distance;
    int onu=0;
    while (distance>0)
    {
        onu=onu*10 + distance%10;
        distance=distance/10;
    }
    return uno==onu;
}

float convert(double distance, string choice){
    if (choice == "meter"){
        return distance;
    }
    else if (choice == "mile"){
        return distance * mile;
    }
    else if (choice == "mile_us"){
        return distance * mile_us;
    }
}
void sort(char arr2[], int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len-i; j++){
            if (arr2[j]>arr2[j+1]){
                char t = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = t;
            }
        }
    }
}
void identifier(char name[50], int len, int arr3[50]){
    sort(name, len);
    for (int i =0; i < len; i++){
        arr3[i] = static_cast<int>(name[i]) * 0.4;
    }
}

int main(){
    char name[50];
    int arr3[50];
    cout << "Введіть ваше ім'я: ";
    cin >> name;
    int len=strlen(name);
    int discount;
    double distance_in_meters;
    double distance_in_km;
    float total_price;
    string measure_system;
    float dist;
    do{
        cout << "Виберіть систему вимірювання: meter/mile/mile_us: ";
        cin >> measure_system;
        cout << "Введіть відстань: ";
        cin >> dist;
    } while (){
        cout << "Відстань поточної доставки: " << distance_in_meters << "m" << endl;
        cout << "Ваша знижка: " << discount << "$" << endl;
        cout << "Накопичена відстань: " << distance_in_km << "km" << endl;
        cout << "Вартість відправки: " << total_price << "$" << endl;
    }
    string file_name = "Combined_deievery.txt";
    ofstream out_file(file_name);
    if (!out_file){
        cerr << "Error while opening" << endl;
    }
    else {
        for (int i =0; i < len; i++){
            out_file << arr3[i] << " ";
        }
    }
    int 
    out_file.close();
}