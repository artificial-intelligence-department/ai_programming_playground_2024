#include <iostream>
#include <string>
using namespace std;

int main(){
    int switcher;
    string weather;
    cout << "What's the weather today? (sunny, rainy, cloudy, snowy, windy)" << endl;
    cin >> weather;
     if (weather != "sunny" && weather !="rainy" && weather != "cloudy" && weather !="snowy" && weather !="windy"){
        cout << "Not correct type of weather." << endl;}
    if (weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy"){
        if (weather == "rainy" || weather == "snowy") {
            cout << "You'd better take jacket!" << endl;}
        else{
            cout << "You don't have to take jacket." << endl;}
        if (weather == "sunny"){
            cout << "What a nice day for a picnic!" << endl;
            switcher=0;}
        else if(weather == "rainy"){
            cout << "That's nice weather for reading book inside." << endl;
            switcher=1;}
        else if (weather == "cloudy"){
            cout << "What about visiting museum?" << endl;
            switcher=2;}
        else if (weather == "snowy"){
            cout << "Let's make a snowman!" << endl;
            switcher=3;}
        else if (weather == "windy"){
            cout << "Fly the kite, if you have it!" << endl;
            switcher=4;}}
        switch(switcher){
            case 0:
                if (weather == "sunny"){
                    cout << "Put on your favourite boots!";
                    break;}
            case 1:
                if (weather == "rainy"){
                    cout << "Rain boots are a nice choice!";
                    break;}           
            case 2:
                if (weather == "cloudy"){
                    cout << "You can wear any boots you want today!";
                    break;}  
            case 3:
                if (weather == "snowy"){
                    cout << "Snowy boots will warm your feet!";
                    break;}  
            case 4:
                if (weather == "windy"){
                    cout << "Put on somethings strong!";
                    break;}
            default:
                break;} 
    return 0;}
