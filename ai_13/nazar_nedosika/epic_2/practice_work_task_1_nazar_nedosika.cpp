#include <iostream>
#include <string>

using namespace std;

int main()
{
    string weather;
    char footWear;

    cout << "Яка зараз погода? (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    if (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy")
    {
        cout << "Будь ласка, введіть дійсну погодну умову!" << endl;
        return 0;
    }

    if(weather == "rainy" || weather == "snowy")
    {
        cout << "Сьогодні краще взяти куртку!" << endl;
    }
    else
    {
        cout << "Куртка не потрібна" << endl;
    }

    if (weather == "sunny")
    {
        cout << "Чудовий день для пікніка!" << endl;
        footWear = 's';
    }
    else if (weather == "rainy")
    {
        cout << "Чудова погода, щоб почитати книгу всередині" << endl;
        footWear = 'r';
    }
    else if (weather == "cloudy")
    {
        cout << "Може відвідати музей?" << endl;
        footWear = 'c';
    }
    else if (weather == "snowy")
    {
        cout << "Як щодо того, щоб зліпити сніговика" << endl;
        footWear = 'n';
    }
    else if (weather == "windy")
    {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
        footWear = 'w';
    }

    switch (footWear)
    {
    case 's':
        cout << "Взуй улюблені кросівки!" << endl;
        break;
    
    case 'r':
        cout << "Дощові чоботи - гарна ідея!" << endl;
        break;

    case 'c':
        cout << "Сьогодні підходить будь-яке взуття" << endl;
        break;

    case 'n':
        cout << "Взуй теплі черевики!" << endl;
        break;

    case 'w':
        cout << "Вибери зручні кросівки" << endl;
        break;

    default:
        cout << "Не знаю, яке взуття обрати(";
        break;
    }

    return 0;
}