#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

string weather;

void inputWeather()
{
    cout << "Write type of weather (sunny/rainy/cloudy/snowy/windy): " << endl;
    cin >> weather;
}

enum enumWeather {
    sunny,
    rainy,
    cloudy,
    snowy,
    windy,
    none
};
 
enumWeather parseToEnum(string w)
{
    if (w == "sunny") return sunny;
    if (w == "rainy") return rainy;
    if (w == "cloudy") return cloudy;
    if (w == "snowy") return snowy;
    if (w == "windy") return windy;
    return none;
}

int main()
{
    bool rightWeather = false;

    while (!rightWeather) {
        inputWeather();

        if ((weather == "sunny") || (weather == "rainy") || (weather == "cloudy") || (weather == "snowy") || (weather == "windy")) {
            rightWeather = true;
        }
        else {
            cout << "Wrong weather. Please enter again." << endl;
        }
    }

    if ((weather == "rainy") || (weather == "snowy")) {
        cout << "You gotta wear a jacket." << endl;
    }
    else {
        cout << "You don't need to wear a jacket." << endl;
    }

    if (weather == "sunny") {
        cout << "It’s a perfect day for a picnic!" << endl;
    }
    else if (weather == "rainy") {
        cout << "It’s a perfect day for reading a book inside!" << endl;
    }
    else if (weather == "cloudy") {
        cout << "Maybe you should go to a museum?" << endl;
    }
    else if (weather == "snowy") {
        cout << "Do you want to build a snowman?" << endl;
    }
    else if (weather == "windy") {
        cout << "Fly a kite if you have one!" << endl;
    }

    enumWeather parsedWeatherEnum = parseToEnum(weather);

    switch (parsedWeatherEnum)
    {
    case sunny:
        cout << "Wear your favorite shoes!" << endl;
        break;
    case rainy:
        cout << "Rainboots are a great idea." << endl;
        break;
    case cloudy:
        cout << "You can wear whatever you want!" << endl;
        break;
    case snowy:
        cout << "Winter boots will keep you warm." << endl;
        break;
    case windy:
        cout << "Wear something tight." << endl;
        break;
    default:
        cout << "You should stay home today!" << endl;
        break;
    }

    return 0;
}
