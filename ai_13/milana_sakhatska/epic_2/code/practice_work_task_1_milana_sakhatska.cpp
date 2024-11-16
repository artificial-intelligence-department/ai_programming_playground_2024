#include <iostream>
#include <string>
using namespace std;

int main() {
    string weather;
    cout << "Введіть поточні погодні умови (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    // Рішення, чи брати куртку
    if (weather == "snowy" || weather == "rainy") {
        cout << "Вам слід взяти куртку." << endl;
    } else {
        cout << "Куртка не потрібна." << endl;
    }

    // Рекомендація щодо активності
    if (weather == "sunny") {
        cout << "Чудовий день для пікніка!" << endl;
    } else if (weather == "rainy") {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    } else if (weather == "cloudy") {
        cout << "Може, відвідати музей?" << endl;
    } else if (weather == "snowy") {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if (weather == "windy") {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    } else {
        cout << "Будь ласка, введіть дійсні погодні умови." << endl;
        return 1; 
    }

    // Рекомендація щодо взуття
    cout << "Рекомендація щодо взуття: ";
    switch (weather[0]) {  // Використовуємо першу букву weather як ключ для switch
        case 's':  // sunny або snowy
            if (weather == "sunny") {
                cout << "Взуй улюблені кросівки!" << endl;
            } else if (weather == "snowy") {
                cout << "Снігові черевики зігріють ваші ноги!" << endl;
            }
            break;
        case 'r':  // rainy
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        case 'c':  // cloudy
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        case 'w':  // windy
            cout << "Одягніть щось міцне!" << endl;
            break;
        default:
            cout << "Будь ласка, введіть дійсні погодні умови." << endl;
            return 1;
    }

    return 0;
}
