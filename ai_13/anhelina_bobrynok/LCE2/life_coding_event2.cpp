#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

//константи
const double British_Mile = 1609.344;
const double US_Mile = 1609.347;
const int Bonus_Mile = 200;
const int Metric_System = 1;

//структура користувача
struct User{
    string name;
    double BonusDistanse;
};

//перевірка чи то є палендром
bool palindrom(int number){
    string numsrt= to_string (number);
    string ReversedSrt= numsrt;
    reverse(ReversedSrt.begin(),ReversedSrt.end());
    return numsrt == ReversedSrt;
}

//перевантажена функція для обрахунку вартості
double CalculateCost(double distance, double rate){
    return distance*rate;
}

//фунція унікального ідефікатора
void UserID(string name, int UserIDMatrix[5][3]){
    sort (name.begin(), name.end());
    int arr [3];
    for (size_t i = 0; i < name.length(); i++){
        double ASCII_Value = name[i]* 0.4;
        if(i>=1 && i<=3){
                arr[i - 1] = static_cast<int>(ASCII_Value);
        }
    }

    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 3; i++){
            UserIDMatrix[i][j] = arr[j]*(i+1);
        }
    }
    
    
}

//рекурсивна функція бонусу
double Bonus(double currentdistance, double &BonusDistance){
    if(palindrom(static_cast<int>(currentdistance))){
        BonusDistance += Bonus_Mile;
    }
    return BonusDistance;
}

int main() {
    
    string UserName;
    double distance;
    double rate;
    double BonusDistanse = 0.0;
    int UserIDMatrix[5][3];
    
    cout<<"Введіть ім'я"<<endl;
    cin>>UserName;

    cout<<"Введіть відстань у метрах"<<endl;
    cin>>distance;

    cout<<"Введіть тариф за метр"<<endl;
    cin>>rate;

    double ResultCost = CalculateCost(distance, rate);

    Bonus(distance, BonusDistanse);
    
    cout<<"Бонусна відстань:"<<BonusDistanse<<"метрів"<<endl;
    cout<<"Загальна сума доставки:"<<ResultCost<<"грн"<<endl;

    UserID(UserName, UserIDMatrix);
    cout<<"Ваш унікальний індифікатор:"<<endl;
    
    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 3; j++){
        cout << setw(5) << UserIDMatrix[i][j]<<endl;
        }
        cout<<endl;
    }
    
    //робота з файлами
    ofstream outFile("collected_distance.txt");
    if(outFile.is_open()){
        outFile<<"ім'я користувача"<< UserName <<endl;
        outFile<<"Відстань:"<< distance <<"метрів"<<endl;
        outFile<<"Бонусна відстань:"<< BonusDistanse <<"метрів"<<endl;
        outFile<<"Вартість доставки:"<< ResultCost <<"грн"<<endl;
        outFile.close();
    }else{
        cerr<<"error"<<endl;
    }

    return 0;
}
