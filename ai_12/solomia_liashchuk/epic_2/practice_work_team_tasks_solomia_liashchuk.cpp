#include <iostream>
#include <string>

using namespace std;

int main()
{
    string weather, shoes;
    string sunny, rainy, cloudy, snowy, windy;
    cout << "Привіт:) Я твій особистий порадник, введи погоду і я допоможу тобі підібрати одяг!(sunny, rainy, cloudy, snowy, windy):  ";
    cin >> weather;

    bool takeJacket = (weather == "rainy" || weather == "snowy");
    if(takeJacket)
    {
        cout << "Одягніть куртку" << endl;
    }
    else
    {
        cout << "Куртка не потрібна" << endl;
    }

    if(weather == "sunny")
    {
        cout << "Чудовий день для пікніка!" << endl;
    }
    else if (weather == "rainy")
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

    switch(weather[0])
    {
        case 's':
        if(weather == "sunny")
        {
            shoes = "Взуй улюблені кросівки!";
        }
        else if(weather == "snowy")
        {
            shoes = "Снігові черевики зігріють ваші ноги!";
        }
        break;
        case 'r':
        shoes = "Дощові чоботи - гарна ідея!";
        break;
        case 'c':
        shoes = "Сьогодні підходить будь-яке взуття.";
        break;
        case 'w':
        shoes = "Одягніть щось міцне!";
        break;
        default:
        shoes = "Не зрозуміла погода";
        break;
    }

    cout << shoes;

    return 0;
}