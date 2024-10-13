#include <iostream>
#include <algorithm>

#define success 0

using namespace std;

enum Weather
{
    Sunny,
    Rainy,
    Cloudy,
    Snowy,
    Windy
};

// Функція переведення стрічки в нижній регістр
inline void stringToLower(string &str)
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
              { return tolower(c); });
    return;
}

int main()
{
    Weather weather;
    string input;
input_point:
    try
    {
        cout << "Enter the weather (Sunny, Rainy, Cloudy, Snowy or Windy): ";
        cin >> input;
        stringToLower(input);
        if (input == "sunny")
        {
            weather = Sunny;
        }
        else if (input == "rainy")
        {
            weather = Rainy;
        }
        else if (input == "cloudy")
        {
            weather = Cloudy;
        }
        else if (input == "snowy")
        {
            weather = Snowy;
        }
        else if (input == "windy")
        {
            weather = Windy;
        }
        else
        {
            throw exception();
        }
    }
    catch (...)
    {
        cout << "Wrong input! Try again." << endl;
        goto input_point;
    }

    cout << endl;

    // Jacket recomendations
    cout << "Jacket recomendations: ";
    if (weather == Snowy || weather == Rainy)
    {
        cout << "You better put on a jacket" << endl;
    }
    else
    {
        cout << "You better not wear a jacket" << endl;
    }

    // Activity recommendation
    cout << "Activity recomendations: ";
    if (weather == Sunny)
    {
        cout << "A great day for a picnic!" << endl;
    }
    else if (weather == Rainy)
    {
        cout << "Perfect weather to read a book inside!" << endl;
    }
    else if (weather == Cloudy)
    {
        cout << "Maybe visit a museum?" << endl;
    }
    else if (weather == Snowy)
    {
        cout << "How about making a snowman?" << endl;
    }
    else if (weather == Windy)
    {
        cout << "Fly a kite if you have one!" << endl;
    }

    // Footwear recommendations
    cout << "Footwear recomendations: ";
    switch (weather)
    {
    case Weather::Sunny:
        cout << "Wear your favorite sneakers!" << endl;
        break;
    case Weather::Rainy:
        cout << "Rain boots are a good idea!" << endl;
        break;
    case Weather::Cloudy:
        cout << "Today, any shoe is suitable." << endl;
        break;
    case Weather::Snowy:
        cout << "Snow boots will keep your feet warm!" << endl;
        break;
    case Weather::Windy:
        cout << "Wear something sturdy!" << endl;
        break;
    }

    cout << endl;

    return success;
}