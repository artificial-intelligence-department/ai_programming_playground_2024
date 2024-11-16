#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather[] = {"sunny", "rainy", "cloudy", "snowy", "windy"};

    string current;
    cout << "Enter weather: " << flush;
    cin >> current;

    int index = 0;
    for(; index < 6; index++) {
        if(current == weather[index]) break;
    }
    if(index > 4) {
        cout << "Enter valid weather! Possible values are: sunny, rainy, cloudy, snowy, windy" << endl;
        return 1; // invalid weather
    }

    if(index == 1 || index == 3) 
        cout << "користувач повинен одягнути куртку." << endl;
    else 
        cout << "куртка не потрібна." << endl;

    if(index == 0) 
        cout << "Чудовий день для пікніка!" << endl;
    else if(index == 1) 
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    else if(index == 2) 
        cout << "Може, відвідати музей?" << endl;
    else if(index == 3) 
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    else if(index == 4) 
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    
    switch(index) {
        case 0:
            cout << "Взуй улюблені кросівки!" << endl;
            break;
        case 1:
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        case 2:
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        case 3:
            cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        case 4:
            cout << "Одягніть щось міцне!" << endl;
            break;
    }
}