#include <iostream>

using namespace std;

enum weathers
{
    SUNNY,
    RAINY, 
    CLOUDY,
    SNOWY,
    WINDY,
    UNKNOWN
};

weathers getWeatherEnum(const string &weather) 
{
    if (weather == "sunny") return SUNNY;
    if (weather == "rainy") return RAINY;
    if (weather == "cloudy") return CLOUDY;
    if (weather == "snowy") return  SNOWY;
    if (weather == "windy") return WINDY;
    return UNKNOWN;
}

int main()
{
    string weather;
    cin >> weather;
    if (weather == "rainy" || weather == "snowy")
    {
        cout << "You should wear a coat" << endl;
    }
    else 
    {
        cout << "No need for a coat today" << endl; 
    }

    if (weather == "sunny")
    {
        cout << "A great day for a picnic!" << endl;
    }
    else if (weather == "rainy")
    {
        cout << "Perfect weather to read a book inside!" << endl;
    }
    else if (weather == "cloudy")
    {
        cout << "Maybe visit a museum?" << endl;
    }
    else if (weather == "snowy")
    {
        cout << "How about making a snowman?" << endl;
    }
    else if (weather == "windy")
    {
        cout << "Fly a kite if you have one!" << endl;
    }

    weathers weathers= getWeatherEnum(weather);
    switch (weathers)
    {
    case 0:
        cout << "Wear your favorite sneakers!" << endl;
        break;
    case 1:
        cout <<"Rain boots are a good idea!" << endl;
        break;
    case 2:
        cout << "Today, any shoe is suitable" << endl;
        break;
    case 3:
        cout <<"Snow boots will keep your feet warm!" << endl;
        break;
    case 4:
        cout <<"Wear something sturdy!" << endl;
        break;
    }
}