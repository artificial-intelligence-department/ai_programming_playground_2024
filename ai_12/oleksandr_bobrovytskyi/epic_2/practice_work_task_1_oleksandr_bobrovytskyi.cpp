#include <iostream>

using namespace std;

int main()
{
    string weather;
    int temp = 0;
    cout << "Enter one of the following variants of the weather:\n -sunny\n -rainy\n -cloudy\n -snowy\n -windy\nWrite it here: ";
    do
    {
        cin >> weather;

        if(!(weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "windy" || weather == "snowy"))
        {
            cout << "Invalid weather type. Please try again. " << endl;
        }
        

    } while (!(weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "windy" || weather == "snowy"));
    
    if (weather == "rainy" || weather == "snowy")
    {
        cout << "You should wear a jacket if you`re planning to go outside today." << endl;
    }

    cout << "Activity for the day:" << endl;

    if(weather == "sunny")
    {
        temp = 1;
        cout << "-It is a great day for a picnic" << endl;
    }
    else if (weather == "rainy")
    {
        temp = 2;
        cout << "-The weather is perfect for staying inside and reading a book." << endl;
    }
    else if (weather == "cloudy")
    {
        temp = 3;
        cout << "-Maybe you should visit the museum?" << endl;
    }
    else if (weather == "windy")
    {
        temp = 4;
        cout << "-You can fly a kite if you have one." << endl;
    }
    else if (weather == "snowy")
    {
        temp = 5;
        cout << "-How about making a snowman?" << endl;
    }

    cout << "Best type of shoes for the day:" << endl;

    switch (temp)
    {
    case 1:
        cout << "-Wear your favorite sneakers!" << endl;
        break;
    case 2:
        cout << "-Rain boots are great idea!" << endl;
        break;
    case 3:
        cout << "-Any type of shoes will fit today." << endl;
        break;
    case 4:
        cout << "-You should wear something sturdy!" << endl;
        break;
    case 5:
        cout << "-Snow boots will warm your legs!" << endl;
        break;
    }

    return 0;
}