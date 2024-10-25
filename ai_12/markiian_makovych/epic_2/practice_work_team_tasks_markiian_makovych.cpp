#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string weather;
    int weatherNum = 0;
    cout << "What the weather is like?" << endl;
    cout << "(Sunny, Rainy, Cloudy, Snowy, Windy)" << endl;

    cin >> weather;

    if (weather != "Sunny" && weather != "Rainy" && weather != "Cloudy" && weather != "Snowy" && weather != "Windy")
    {
        cout << "Make sure that you type correct weather" << endl;
        return 0;
    }

    if (weather == "Snowy" || weather == "Rainy")
    {
        cout << "Grab a coat" << endl;
    }
    else
    {
        cout << "You don`t need a coat" << endl;
    }

    if (weather == "Sunny")
    {
        cout << "Go on a picnic" << endl;
        weatherNum = 1;
    }
    else if (weather == "Rainy")
    {
        cout << "Read a book!" << endl;
        weatherNum = 2;
    }
    else if (weather == "Cloudy")
    {
        cout << "Maybe a museum?" << endl;
        weatherNum = 3;
    }
    else if (weather == "Snowy")
    {
        cout << "Let`s build a snowman!" << endl;
        weatherNum = 4;
    }
    else
    {
        cout << "Fly a kite if you have one" << endl;
        weatherNum = 5;
    };

    switch (weatherNum)
    {
    case 1:
        cout << "Put on favourite snickers!" << endl;
        break;
    case 2:
        cout << "Wellington boots it`s your choice!" << endl;
        break;
    case 3:
        cout << "Every pair of shoes is suitable" << endl;
        break;
    case 4:
        cout << "Winter boots will warm you" << endl;
        break;
    case 5:
        cout << "Put on something thick" << endl;
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    };

    return 0;
}