#include <iostream>
#include <string>

using namespace std;

int main()
{
    int weathernum;
    string weather;
    cout << "What's the weather like today? (options: sunny, rainy, cloudy, snowy, windy)" << endl;
    do{
        getline(cin, weather);
        if (weather=="sunny" || weather=="rainy" || weather=="cloudy" || weather=="snowy" || weather=="windy")
        {
            break;
        }
        cout << "Invalid type of weather, try again." << endl;
    } while (weather!="sunny" && weather!="rainy" && weather!="cloudy" && weather!="snowy" && weather!="windy");
    if (weather=="snowy" || weather=="rainy")
    {
        cout << "Put on a jacket!" << endl;
    }
    else 
    {
        cout << "You don't need to put on a jacket." << endl;
    }
    if (weather=="sunny")
    {
        cout << "Perfect day for a picnic!" << endl;
        weathernum=1;
    }
    else if (weather=="rainy")
    {
        cout << "Perfect weather to stay inside and read a book!" << endl;
        weathernum=2;
    }
    else if (weather=="cloudy")
    {
        cout << "How about visiting a museum?" << endl;
        weathernum=3;
    }
    else if (weather=="snowy") 
    {
        cout << "Let's make a snowman!" << endl;
        weathernum=4;
    }
    else if (weather=="windy")
    {
        cout << "Launch a kite, if you have one." << endl;
        weathernum=5;
    }
    switch (weathernum)
    {
    case 1:
        cout << "Put on your favorite sneakers!" << endl;
        break;  
    case 2:
        cout << "Rain boots - great idea!" << endl;
        break;
    case 3:
        cout << "Any shoes are good today." << endl;
        break;
    case 4:
        cout << "Snow boots will warm your toes!" << endl;
        break;
    case 5:
        cout << "Put on something sturdy!" << endl;
        break;
    default:
        cout << "Something's off...";
        break;
    }
}