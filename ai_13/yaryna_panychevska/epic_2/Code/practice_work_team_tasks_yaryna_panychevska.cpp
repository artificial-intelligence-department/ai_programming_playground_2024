#include <iostream>
using namespace std;

int main()
{
    enum WeatherType
    {
        Sunny = 1,
        Cloudy,
        Snowy,
        Windy,
        Rainy
    };

    int Weather_Input;

    do
    {
        cout << "\nSunny - [1]\nCloudy - [2]\nSnowy - [3]\nWindy - [4]\nRainy - [5]";
        cout << "\nEnter a number: " << endl;
        cin >> Weather_Input;

        if (Weather_Input > 5 || Weather_Input < 1)
        {
            cout << "Invalid input :(";
            cout << "\n";
        }
    } while (Weather_Input > 5 || Weather_Input < 1);

    switch (Weather_Input)
    {
    case Sunny:
        cout << "Sneakers will be a perfect choice.\n";
        break;

    case Cloudy:
        cout << "On cloudy days, I can recommend wear something comfortable for unpredictable conditions\nFor example water-resistant sneakers or leather boots.\n";
        break;

    case Snowy:
        cout << "You should keep your feet warm, snow boots will be perfect.\n";

        break;

    case Windy:
        cout << "For this weather it's better to wear something that is stable and provide coverage.\nLeather boots are perfect for this!\n";

        break;
    case Rainy:
        cout << "If you want to go outside I recommend to wear rain boots or waterproof sneakers.\n";
        break;
    }
    //-----------------------------------------------------------------------------------//
    if (Weather_Input == Sunny)
    {
        cout << "And it will be warm, so you won't need a jacket.\n";
        cout << "A good day to go outside and get some vitamin D :)";
    }
    else if (Weather_Input == Cloudy || Weather_Input == Rainy)
    {
        cout << "And you should wear jacket, it will be cold!\n";
        cout << "But the best option is to stay at home and drink hot tea.\n";
    }
    else if (Weather_Input == Snowy)
    {
        cout << "And you should definetly wear jacket!\n";
        cout << "Best time to be a child again and make snowmans :)";
    }

    return 0;
}