#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

string weather;

void enterWeather()
{
    cout << "Enter type of weather today(sunny/rainy/cloudy/snowy/windy): " << "\n";
    cin >> weather;
}

enum eWeather
{
    sunny,
    rainy,
    cloudy,
    snowy,
    windy,
    none
};

eWeather returnEnum(string weather1)
{
    if(weather1 == "sunny")
    return sunny;
    if(weather1 == "rainy")
    return rainy;
    if(weather1 == "cloudy")
    return cloudy;
    if(weather1 == "snowy")
    return snowy;
    if(weather1 == "windy")
    return windy;
    return none;
}

int main()
{
    bool weather0 = false;

    while(!weather0)
    {
        enterWeather();
        if((weather == "sunny") || (weather == "rainy") || (weather == "cloudy") || (weather == "snowy") || (weather == "windy"))
        {
            weather0 = true;
        }
        else
        {
            cout << "Wrong! Try again" << "\n";
        }
    }

    if((weather == "rainy") || (weather == "snowy"))
    {
        cout << "You have to wear a jacket!" << "\n";
    }
    else
    {
        cout << "You don't have to wear a jacket" << "\n";
    }

    if(weather == "sunny")
    {
        cout << "It's a great day to have a picnic!" << "\n";
    }
    else if(weather == "rainy")
    {
        cout << "It's a great weather to read a book inside!" << "\n";
    }
    else if(weather == "cloudy")
    {
        cout << "Maybe you would like to visit meseum?" << "\n";
    }
    else if(weather == "snowy")
    {
        cout << "Would you like to make a snowman?" << "\n";
    }
    else if(weather == "windy")
    {
        cout << "Launch a kite into the sky if you have one!" << "\n";
    }

    eWeather returnWeatherE = returnEnum(weather); 

    switch(returnWeatherE)
    {
        case sunny:
        cout << "Wear your favourite shoes!" << "\n";
        break;

        case rainy:
        cout << "Rain boots is a great idea!" << "\n";
        break; 

        case cloudy:
        cout << "Today you can wear any shoes!" << "\n";
        break;

        case snowy:
        cout << "Snow boots will warm your feet!" << "\n";
        break;

        case windy:
        cout << "Wear something tough!" << "\n";
        break;

        default: 
        cout << "You should stay at home today!" << "\n";
        break;
    }

    return 0;
}