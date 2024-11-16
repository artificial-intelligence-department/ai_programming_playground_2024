#include <iostream>
using namespace std;

int main() {
    string weather;
    bool valid;

    do {
        cout << "Введіть погодні умови із запропонованих: \n"
             << "sunny, rainy, cloudy, snowy, windy\n";
        cin >> weather;

        valid = (weather == "rainy" || weather == "sunny" || weather == "cloudy" || weather == "snowy" || weather == "windy");

        if (valid) {
            cout << "Поради щодо погоди та активностей: \n";
            if (weather == "rainy" || weather == "snowy") {
                cout << "Краще візьміть куртку\n";
            }else cout << "Куртка не потрібна, буде тепло!\n";
            if (weather == "sunny") {
                cout << "Чудовий день для пікніка!\n";
            } else if (weather == "rainy"){
                cout << "Ідеальна погода, щоб читати книгу всередині!\n";
            }else if (weather == "cloudy"){
                cout << "Може, відвідати музей?\n";
            }else if (weather == "snowy"){
                cout << "Як щодо того, щоб зліпити сніговика?\n";
            }else cout << "Запустіть повітряного змія, якщо він у вас є!\n";
            switch (weather[0])
            {
            case 's':
                if (weather == "sunny") {
                        cout << "Взуй улюблені кросівки!\n";
                    } else if (weather == "snowy") {
                        cout << "Снігові черевики зігріють ваші ноги!\n";
                    }
                break;
            case 'r':
                cout << "Дощові чоботи - гарна ідея!\n";
                break;
            case 'c': 
                cout << "Сьогодні підходить будь-яке взуття.\n";
                break;
            case 'w':
                cout << "Одягніть щось міцне!\n";
            default:
                break;
            }
        } else{
            cout << "Ви вказали невідому для мене погоду, будь ласка спробуйте ще раз.\n";
        }

    } while (!valid);


    return 0;
}
