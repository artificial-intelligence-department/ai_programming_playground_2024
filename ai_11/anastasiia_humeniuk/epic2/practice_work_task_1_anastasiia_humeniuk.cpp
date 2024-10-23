#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    
    cout << "Введіть поточні погодні умови (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;
      if (weather != "sunny" && weather != "rainy" && weather != "cloudy" && 
        weather != "snowy" && weather != "windy") {
        cout << "Будь ласка, введіть дійсну погодну умову." << endl;
        return 1; 
    }
    if (weather == "rainy" || weather == "snowy") {
        cout << "Одягніть куртку!" << endl;
    } else {
        cout << "Куртка не потрібна." << endl;
    }
    
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
switch (weather[1]) {
        case 'u':
            cout << "Взуй улюблені кросівки!" << endl;
            break;
        case 'n':
             cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        case 'a': 
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        case 'l': 
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        default:
            cout << "Одягніть щось міцне!" << endl;
            break;
      
    }

    return 0;
}
   /* switch (weather) {
        case "sunny":
           cout << "Взуй улюблені кросівки!" << endl;
            break;
        case "rainy":
            cout << "Дощові чоботи - гарна ідея!" << endl;
           break;
        case "cloudy":
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        case "snowy":
            cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        case "windy":
            cout << "Одягніть щось міцне!" << endl;
            break;
        default:
            cout << "Будь ласка, введіть дійсну погодну умову." << endl;
            break;
    }

    return 0;
} *\