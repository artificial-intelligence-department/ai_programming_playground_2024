#include <iostream>
#include <string>

using namespace std;

bool IsWalidWeather(string weather)
{
    if (weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy")
    {
        return true;
    }
    else
    {
        return false;
    }

}

void CheckJacket(string weather)
{
    if(weather == "rainy" || weather == "snowy")
    {
        cout << "Краще одягніть куртку." << endl;
    }
    else
    {
        cout << "Куртка не потрбіна сьогодні." << endl;
    }
}

void RecomendActivity(string weather)
{
    if(weather == "sunny")
    {
        cout << "Чудовий день для пікніка!" << endl;
    }

    else if(weather == "rainy")
    {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    }

    else if(weather == "cloudy")
    {
        cout << "Може, відвідати музей?" << endl;
    }

    else if(weather == "snowy")
    {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    }

    else if(weather == "windy")
    {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }
}

enum Weather 
{
    sunny,
    rainy,
    cloudy,
    snowy,
    windy
};
Weather GetWeatherNum(string weather)
{
    if (weather == "sunny") return sunny;
    else if (weather == "rainy") return rainy;
    else if (weather == "cloudy") return cloudy;
    else if (weather == "snowy") return snowy;
    else if (weather == "windy") return windy;
    return sunny; 
    
}

void CheckBoot(Weather weather)
{
    switch (weather)
    {
    case sunny: cout << "Взуй улюблені кросівки!" << endl; break;
    case rainy: cout << "Дощові чоботи - гарна ідея!" << endl; break;
    case cloudy: cout << "Сьогодні підходить будь-яке взуття." << endl; break;
    case snowy: cout << "Снігові черевики зігріють ваші ноги!" << endl; break;
    case windy: cout << "Одягніть щось міцне!" << endl; break;
    
    default:break;
    }
}

int main()
{
    cout << "======== Personal advisor ========" << endl;

    string weather;

    do{
    cout << "Enter weather: ";
    cin >> weather;
    } while(!IsWalidWeather(weather));
        
    Weather weath = GetWeatherNum(weather);

    CheckJacket(weather);
    RecomendActivity(weather);
    CheckBoot(weath);
    
    return 0;
}