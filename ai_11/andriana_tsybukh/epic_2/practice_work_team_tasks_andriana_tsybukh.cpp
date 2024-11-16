#include <iostream>
#include <string>
using namespace std;

int main() {
    string weather, shoes;

    cout << "Введіть погодні умови (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    if (weather == "snowy" || weather == "rainy") {
        cout << "Вам варто взяти куртку!" << endl;
    } else if (weather == "sunny" || weather == "cloudy" || weather == "windy") {
        cout << "Куртка не потрібна" << endl;
    } 

    cout << "Рекомендація активності: " << endl;
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
    } 

    cout << "Рекомендація взуття: " << endl;
    switch (weather[0]) {
        case 's':
        if (weather == "sunny") {
            shoes = "Взуй улюблені кросівки!";
        } else if (weather == "snowy") {
            shoes = "Снігові черевики зігріють ваші ноги!";
        }
        break;
        case 'r':
        shoes = "Дощові чоботи - гарна ідея!";
        break;
        case 'c':
        shoes = "Сьогодні підходить будь-яке взуття!";
        break;
        case 'w':
        shoes = "Одягніть щось міцне!";
        break;
    }
    cout << shoes << endl;
    
    return 0;

}
