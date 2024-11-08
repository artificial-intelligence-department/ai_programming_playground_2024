#include<iostream>
using namespace std;

int main(){
    string weather;

    cout << "Введіть поточні погодні умови:" << endl
         << "- sunny" << endl
         << "- rainy" << endl
         << "- cloudy" << endl
         << "- snowy" << endl
         << "- windy" << endl;

    cin >> weather;


    if (weather == "sunny")
        cout << "Чудовий день для пікніка!" << endl;
    else if (weather == "rainy")
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    else if (weather == "cloudy")
        cout << "Може, відвідати музей?" << endl;
    else if (weather == "snowy")
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    else if (weather == "windy")
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    else{
        cout << "Введіть дійсну умову";
        return 0;
        }


    if (weather == "rainy" || weather == "snowy")
        cout << "Краще прихопіть куртку" << endl;
    else
        cout << "Куртка не потрібна" << endl;


    switch(weather[0]){
        case 's':
            if (weather == "sunny")
                cout << "Взуй улюблені кросівки!";
            else
                cout << "Снігові черевики зігріють ваші ноги!";
            break;
        case 'r':
            cout << "Дощові чоботи - гарна ідея!";
            break;
        case 'c':
            cout << "Сьогодні підходить будь-яке взуття";
            break;
        case 'w':
            cout << "Одягніть щось міцне!";
            break;
    }

    return 0;
}