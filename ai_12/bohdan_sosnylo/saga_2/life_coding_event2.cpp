#include <iostream>
#include <iomanip>   
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

struct user{

char* name;
int distance;

int bonus;

};

void Addf(user users, string filename){
    ofstream file(filename, ios::app);
    if(file){
        
        file.write(reinterpret_cast<char*>(&users), sizeof(users));
        
    }
}

void display(user users, string filename, char* name){
    ifstream file(filename, ios::app);
    
    if(file){
        file.read(reinterpret_cast<char*>(&users), sizeof(users));
        if(users.name == name ){
            cout << users.distance <<" " << users.bonus;

        }
        
    }
}

bool isPalindrome(int num) {
   
    if (num < 0) {
        return false;
    }
    
    int rev = 0;
    int orig = num;

    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }

    return orig == rev;
}

double convert(int num, char* measure){
    if(measure == "meter"){
        return num;
    }
    else if(measure == "mile"){
        return num*1609.347;
    }
    else if(measure == "mile_us"){
        return num*1609.344; 
    }
}

char* sort(char* mas){
    for(int i = 0; i<sizeof(mas)/sizeof(mas[0]);i++){
        for(int k = 0;k<sizeof(mas)/sizeof(mas[0]);k++){
            if(mas[k]>mas[k+1]){
                swap(mas[k],mas[k+1]);
            }

        }
    }
    return mas;
}

int* masint(char* mas, int size){
    int* intmas = new int[size];
    for(int i = 0;i<size;i++){
        intmas[i] = static_cast<int>(mas[i]);
    }
    return intmas;
}

int main(){

char* filename = "distance.txt";
user users;
char * measure;

cout << "Введіть ваше ім'я: ";
cin >> users.name;

cout << "Введіть відстань: ";
cin >> users.distance;

cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
cin >> measure;

users.distance = convert(users.distance, measure);

cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";


if(isPalindrome(users.distance)){
    users.bonus+= 200000;
}
char r;
cin >> r;

Addf(users,filename);

    return 0;
}