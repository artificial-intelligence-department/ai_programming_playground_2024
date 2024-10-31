#include <iostream>
#include <string>
using namespace std;
int main() {
    enum class Weather {
        sunny,
        rainy,
        cloudy,
        snowy,
        windy,
    };
    cout << "Tell us about weather today! Enter 0 for sunny, 1 for rainy, 2 for cloudy, 3 for snowy, 4 for windy: ";
    int weather;
    cin >> weather;
    if (weather>4 || weather<0) {
        cout << "Error, wrong input - try agian!";
    }
    else {
        //Рішення чи брати куртку
        cout << "Should you wear a jacket?\n";
        if(weather ==1 || weather == 3)
        cout << "You have to wear a jacket!\n";
        else 
        cout << "You don`t have to wear a jacket!\n";
        //Рекомендація щодо активності
        cout << "What about an activity?\n";
        if(weather == 0)
        cout << "Nice day to go on a picknick\n"; 
        else if(weather == 1)
        cout << "Should we read a book inside?\n";
        else if(weather == 2)
        cout << "What about museum?\n";
        else if(weather == 3)
        cout << "Should we make a snowman?\n";
        else if(weather == 4)
        cout << "Fly a kite, if you have one!\n";
        //Рекомендації щодо взутття
        cout << "What about boots?\n";
        switch(weather) {
            case(0): cout << "Wear your lovely snickers\n";
            break;
            case(1): cout << "Rain boots are nice idea!\n";
            break;
            case(2): cout << "You can wear anything!\n";
            break;
            case(3): cout << "Snow boots are your choice!\n";
            break;
            case(4): cout << "Wear something stronger!\n";
            break;
            default:
            break;
        }
    }
    return 0;
}