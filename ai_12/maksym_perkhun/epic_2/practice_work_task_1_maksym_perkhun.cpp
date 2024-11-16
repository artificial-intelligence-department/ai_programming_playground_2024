#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    cout << "Bведiть поточнi погоднi умови (sunny, rainy, cloudy, snowy, windy): ";
    while(true){
        cin >> weather;
        if(weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy"){
            break;
        }
        else{
        cout << "Введіть правильне значення: ";
        }
    }   
    
    
    if (weather == "snowy" || weather == "rainy") {
        cout << "Не забудьте взяти куртку!" << endl;
    }
    else {
        cout << "Куртка не потрібна." << endl;
    }
    if (weather == "sunny") {
        cout << "Чудовий день для пікніка!" << endl;
    }
    else if (weather == "rainy") {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    }
    else if (weather == "cloudy") {
        cout << "Може, відвідати музей?" << endl;
    }
    else if (weather == "snowy") {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    }
    else if (weather == "windy") {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }
    
    switch (weather[0]) {
    case 's':
        if (weather == "sunny") {
            cout << "Взуй улюблені кросівки!" << endl;
            break;
        }
        else {
            cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        }
    case 'r':
        cout << "Дощові чоботи - гарна ідея!" << endl;
        break;
    case 'c':
        cout << "Сьогодні підходить будь-яке взуття." << endl;
        break;
    case 'w':
         cout << "Одягніть щось міцне!" << endl; 
        break;
        }
    return 0;
}
