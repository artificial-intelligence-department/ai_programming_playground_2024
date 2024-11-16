#include <iostream>
#include <string>
using namespace std;

enum Condition {sunny, rainy, cloudy, snowy, windy, unknown}; 

Condition getCondition(const string& weather) {
    if (weather == "sunny") return sunny;
    if (weather == "rainy") return rainy;
    if (weather == "cloudy") return cloudy;
    if (weather == "snowy") return snowy;
    if (weather == "windy") return windy;
    else return unknown;
}

int main() {
    string weather;
    cout << "введіть поточні погодні умови (sunny/rainy/cloudy/snowy/windy): ";
    cin >> weather;
    
    Condition condition = getCondition(weather);

    if (condition == unknown) {
        cout << "Введіть дійсну умову";
        return 0;
    }

    if (condition == rainy||condition == snowy) {
        cout << "Одягніть куртку" << endl;
    }
    else {
        cout << "Куртка не потрібна" << endl;
    }


    if (condition == sunny) {
        cout << "Чудовий день для пікніка!" << endl;
    }
    else if (condition == rainy) {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    }
    else if (condition == cloudy) {
        cout << "Може, відвідати музей?" << endl;
    }
    else if (condition == snowy) {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    }
    else if (condition == windy) {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }

    switch(condition) {
        case sunny: cout << "Взуй улюблені кросівки!";
        break;
        case rainy: cout << "Дощові чоботи - гарна ідея!";
        break;
        case cloudy: cout << "Сьогодні підходить будь-яке взуття.";
        break;
        case snowy: cout << "Снігові черевики зігріють ваші ноги!";
        break;
        case windy: cout << "Одягніть щось міцне!";
        break;
    }

    return 0;
}