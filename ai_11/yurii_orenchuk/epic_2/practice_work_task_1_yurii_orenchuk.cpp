#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    string weather;

    cout << "Введіть поточну погоду (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    if (!(weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy")){
        cout << "Ви не ввели правильне значення, спробуйте ще раз.";
        return 0;
    }

    if (weather == "snowy" || weather == "rainy"){
        cout << "Ви повинні взяти куртку\n";
    }
    else{
        cout << "Можете куртку не брати\n";
    }

    if (weather == "sunny"){
        cout << "Чудовий день для пікніка!\n";
    }
    else if (weather == "rainy"){
        cout << "Ідеальна погода, щоб читати книжку всередині!\n";
    }
    else if (weather == "cloudy"){
        cout << "Може, відвідати музей?\n";
    }
    else if (weather == "snowy"){
        cout << "Як щодо того, щоб зліпити сніговика?\n";
    }
    else if (weather == "windy"){
        cout << "Запустіть повітряного змія, якщо він у вас є!\n";
    }

    std::map <std::string, int> mapping;
    mapping["sunny"] = 1;
    mapping["rainy"] = 2;
    mapping["cloudy"] = 3;
    mapping["snowy"] = 4;
    mapping["windy"] = 5;

    switch (mapping[weather]) {
        case 1:
        cout << "Взуй улюблені кросівки!";
        break;
        case 2:
        cout << "Дощові чоботи - гарна ідея!";
        break;
        case 3:
        cout << "Сьогодні підходить будь-яке взуття.";
        break;
        case 4:
        cout << "Снігові черевики зігріють ваші ноги!";
        break;
        case 5:
        cout << "Одягніть щось міцне!";
        break;
    }
    return 0;
}