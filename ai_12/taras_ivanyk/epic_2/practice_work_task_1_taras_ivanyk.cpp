#include <iostream>
using namespace std;

int main()
{
    string weather;
    do{
    cout << "What is the weather like today?" << endl;
    cin >> weather;

    if (weather == "rainy" || weather == "snowy"){
    cout << "Please, wear a jacket" << endl;
    }
    else if(weather == "sunny" || weather == "windy" || weather == "cloudy"){
    cout << "You don't need a jacket" << endl;
    }
    else{
        cout << "Enter another type of weather(options: sunny, rainy, cloudy, snowy, windy)";
        continue; // типу на все інше не звартаю увагу, якщо введена некоректна погода
    }

    if (weather == "sunny")
    {
        cout << "Great day for a picnic!" << endl;
    }
    else if (weather == "rainy")
    {
        cout << "An ideal weather to reed a book inside!" << endl;
    }
    else if (weather == "cloudy")
    {
        cout << "Maybe, you should go to museum?" << endl;
    }
    else if (weather == "snowy")
    {
        cout << "What about making a snowman?" << endl;
    }
    else if (weather == "windy")
    {
        cout << "Fly a kite if you have one!" << endl;
    }

    int weatherType = 0;

    if (weather == "sunny"){
        weatherType = 1;
    }
    else if (weather == "rainy"){
        weatherType = 2;
    }
    else if (weather == "cloudy"){
        weatherType = 3;
    }
    else if (weather == "snowy"){
        weatherType = 4;
    }
    else if (weather == "windy"){
        weatherType = 5;
    }

    switch (weatherType)
    {
    case 1:
        cout << "Wear your favourite shoes!" << endl;
        break;
    case 2:
        cout << "Rain boots are a good idea!" << endl;
        break;
    case 3:
        cout << "Today, any shoe is suitable." << endl;
        break;
    case 4:
        cout << "Snow boots will keep your feet warm!" << endl;
        break;
    case 5:
        cout << "Wear something sturdy!" << endl;
        break;
    default:
        break;
    }
}
while (weather != "windy" && weather != "rainy" && weather != "sunny" && weather != "cloudy" && weather != "snowy" );
    return 0;
}