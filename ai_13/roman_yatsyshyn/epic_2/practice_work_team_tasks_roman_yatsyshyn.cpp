#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// sunny
// rainy
// cloudy
// snowy
// windy


int main(){
    string weather_status;
    string weather_status_lower;
    string weather_options[3] = {"sunny", "rainy", "cloudy"};
    int idx = 0;
    int n = 0;

    cout << "What's the weather outside?\n";
    cin >> weather_status;

    for (char ch : weather_status) {
        // Convert each character to lowercase using tolower
        weather_status_lower += tolower(ch);
    }

    // If/Else

    if (weather_status_lower == "rainy" || weather_status_lower == "snowy")
    {
        cout << "Одягни куртку!\n";
    }
    else
    {
        cout << "Куртка тобі не потрібна!\n";
    }
    
    // If/Elif

    if (weather_status_lower == "sunny")
    {
        cout << "Чудовий день для пікніка!\n";
    }
    else if (weather_status_lower == "rainy")
    {
        cout << "Ідеальна погода, щоб читати книгу всередині!\n";
    }
    else if (weather_status_lower == "cloudy")
    {
        cout << "Може, відвідати музей?\n";
    }
    else if (weather_status_lower == "snowy")
    {
        cout << "Як щодо того, щоб зліпити сніговика?\n";
    }
    else if (weather_status_lower == "windy")
    {
        cout << "Запустіть повітряного змія, якщо він у вас є!\n";
    }
        
    // Switch case

    for (idx = 0; idx < 3; idx++) {
        if (weather_options[idx] == weather_status_lower) {
            n = idx;
            // cout << "Weather is " << weather_status << ", so index is " << n << "\n";
        }
    }

    switch (n)
    {
    case 0:
        cout << "Взуй улюблені кросівки!";
        break;
    case 1:
        cout << "Дощові чоботи – гарна ідея!";
        break;
    case 2:
        cout << "Сьогодні підходить будь-яке взуття.";
        break;
    }
    return 0;
}