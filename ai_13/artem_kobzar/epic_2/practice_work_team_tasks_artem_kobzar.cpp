#include <iostream>
#include <string>

using namespace std;

enum weather
{
    sunny,
    cloudy,
    windy,
    rainy,
    snowy
};

bool Weather_type(string weather) {
    if (weather =="sunny" || weather =="cloudy" || weather =="windy" || weather =="rainy" || weather =="snowy")
    {
        return true;
    } else {
        return false;
    }
}

void Activity_type(weather w) {
    if (w==sunny) 
    {
        cout<<"It's a great day for a picnic with your friends!"<<endl;
    } else if (w==cloudy)
    {
        cout<<"Probably time for visiting the museum?"<<endl;
    } else if (w==windy)
    {
        cout<<"If you have a kite, it is time to use it!"<<endl;
    } else if (w==rainy)
    {
        cout<<"Perfect weather for reading a book inside your cozy house!"<<endl;
    } else if (w==snowy)
    {
        cout<<"Get up and go make a snowman!"<<endl;
    }
}

void Jacket_need(weather w) {
    if (w==snowy || w==rainy)
    {
        cout<<"You should put on your jacket!"<<endl;
    } else 
    {
        cout<<"You don't have to wear jacket today"<<endl;
    }
}

int main()
{
    string weather_input;
    weather w;

    do {
    cout<<"Enter the type of weather you have(sunny, cloudy, windy, rainy, snowy): ";
    cin>>weather_input;   
        if (Weather_type(weather_input)) {
            if (weather_input == "sunny") {
                w = sunny;
            } else if (weather_input == "cloudy") {
                w = cloudy;
            } else if (weather_input == "windy") {
                w = windy;
            } else if (weather_input == "rainy") {
                w = rainy;
            } else if (weather_input == "snowy") {
                w = snowy;
            }
        } else {
            cout << "Invalid input, please try again." << endl;
        }  
    } while (!Weather_type(weather_input));

    Activity_type(w);
    Jacket_need(w);
    switch(w) {
    case sunny: cout<<"Wear your favourite sneakers!"<<endl;
    break;
    case cloudy: cout<<"You can wear all the boots you want!"<<endl;
    break;
    case windy: cout<<"Wear something more durable!"<<endl;
    break;
    case rainy: cout<<"Put on your rainy boots!"<<endl;
    break;
    case snowy: cout<<"It's time for winter shoes!"<<endl;
    break;
    default:
    break;
}
return 0;
}