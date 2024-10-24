#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
    int StandartTicket = 1000;//Стандартна ціна квитка
    int Age;
    int RoundTicket = StandartTicket * 10/100; //знижка 10 % для типу поїздки "Туди-назад"
    int NewTicket1;
    int NewTicket2;
   string TripType;
do{
    cout << "Enter your age: " << endl;
    cin >> Age;
    if (Age < 0)
    {
        cout << "Your age is not valid. Please, eter again. " << endl;
    }
    
}while(Age < 0); 

cout << "Enter trip type (One-way, Round): " << endl;
cin >> TripType;

if( Age < 12 && TripType == "One-way")//Знижка для дітей віком від 0-11 років
{
    NewTicket1 = StandartTicket * 50 / 100;
    NewTicket2 = StandartTicket - NewTicket1;
cout << "Your ticket price: " << NewTicket2 << " hryvnias" << endl;
}
else if (Age < 12 && TripType == "Round") // Знижка для дітей віком 0-11 років + знижка на квиток
{
    NewTicket1 = StandartTicket - RoundTicket;
    NewTicket1 = NewTicket1 * 50 / 100; 
    cout << "Your ticket price: " << NewTicket1 << " hryvnias" << endl;
}
else if ( Age > 60 && TripType == "One-way")//Знижка для доролсих вікод від 61-100+
{
    NewTicket1 = 1000 * 30 / 100;
    NewTicket2 = StandartTicket - NewTicket1;
    cout << "Your ticket price: " << NewTicket2 << " hryvnias" << endl;
}
else if (Age > 60 && TripType == "Round") // Знижка для доролсих вікод від 61-100+ + знижка на квиток
{
    NewTicket1 = StandartTicket - (StandartTicket *30 / 100);
    NewTicket2 = NewTicket1 -RoundTicket;
    cout << "Your ticket price: " << NewTicket2 << " hryvnias" << endl;
}
else if (Age >= 12 && Age <= 60 && TripType == "One-way")//Ціна для людей віком від 12 до 60 років
{
    cout << "Your ticket price: " << StandartTicket << " hryvnias" << endl;
}
else if (Age >= 12 && Age <= 60 && TripType == "Round")//Ціна для людей віком від 12 до 60 років + знижка на квиток
{
    NewTicket1 = StandartTicket - RoundTicket;
    cout << "Your ticket price: " << NewTicket1 << " hryvnias" << endl;
}
    return 0;
}