#include <iostream>
#include <string>

using namespace std;

enum Weather { SUNNY, RAINY, CLOUDY, SNOWY, WINDY, INVALID };

Weather getWeatherEnum(const string& weather) {
    if (weather == "sunny") return SUNNY;
    if (weather == "rainy") return RAINY;
    if (weather == "cloudy") return CLOUDY;
    if (weather == "snowy") return SNOWY;
    if (weather == "windy") return WINDY;
    return INVALID;
}

int main() {
    string weather;
    cout << "Enter your weather: ";
    cin >> weather;

    Weather currentWeather = getWeatherEnum(weather);

    if (currentWeather == SNOWY || currentWeather == RAINY) {
        cout << "Одягни куртку." << endl;
    } else {
        cout << "Куртка непотрібна." << endl;
    }

    if (currentWeather == SUNNY) {
        cout << "Чудовий день для пікніка!" << endl;
    } else if (currentWeather == RAINY) {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    } else if (currentWeather == CLOUDY) {
        cout << "Може, відвідати музей?" << endl;
    } else if (currentWeather == SNOWY) {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if (currentWeather == WINDY) {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    } else {
        cout << "Будь ласка, введіть дійсну погоду." << endl;
        return 0; // Завершити програму, якщо погода недійсна
    }

    switch (currentWeather) {
        case SUNNY:
            cout << "Взуй улюблені кросівки!" << endl;
            break;
        case RAINY:
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        case CLOUDY:
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        case SNOWY:
            cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        case WINDY:
            cout << "Одягніть щось міцне!" << endl;
            break;
        default:
            break;
    }
}