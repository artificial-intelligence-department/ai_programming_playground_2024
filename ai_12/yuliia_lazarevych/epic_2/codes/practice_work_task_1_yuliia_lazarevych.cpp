#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    cout << "Введіть погоду (windy, rainy, cloudy, snowy, sunny): ";
    cin >> weather;

    cout << "Перевірка на потребу в куртці: ";
    if (weather == "snowy" || weather == "rainy") {
        cout << "Візьміть куртку" << endl;
    } else {
        cout << "Вам не потрібна куртка" << endl;
    }

    cout << "Рекомендація щодо активностей: ";
    if (weather == "sunny") {
        cout << "Чудовий день для пікніка!" << endl;
    } else if (weather == "rainy") {
        cout << "Ідеальна погода, щоб читати книгу всередині" << endl;
    } else if (weather == "cloudy") {
        cout << "Може, відвідати музей?" << endl;
    } else if (weather == "snowy") {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if (weather == "windy") {
        cout << "Запустіть повітряного змія, якщо він у вас є" << endl;
    } else {
        cout << "Невідома погода" << endl;
        return 0;
    }
    
    cout << "Рекомендація щодо взуття: ";
    int weatherType = 0;  //робимо змінні типу інт для свіч-кейсів
    if (weather == "sunny") {
        weatherType = 1;
    } else if (weather == "rainy") {
        weatherType = 2;
    } else if (weather == "cloudy") {
        weatherType = 3;
    } else if (weather == "snowy") {
        weatherType = 4;
    } else if (weather == "windy") {
        weatherType = 5;
    }

    switch (weatherType) {
        case 1:
            cout << "Взуй улюблені кросівки!" << endl;
            break;
        case 2:
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        case 3:
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        case 4:
            cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        case 5:
            cout << "Одягніть щось міцніше!" << endl;
            break;
        default:
            cout << "Немає рекомендацій щодо взуття" << endl;
    }

    return 0;
}
