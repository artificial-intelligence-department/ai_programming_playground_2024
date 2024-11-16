#include <iostream>

using namespace std;

int main (){
    string weather;
    do {
    cout << "Введіть значення погоди (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;
    } while (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy");


    if (weather == "rainy" || weather == "snowy"){
    cout << "Вам треба взяти куртку" << endl;
    } else {
        cout << "Куртка не потрібна" << endl;
    }

    cout << "Рекомендація щодо активності: " << endl;
    if (weather == "sunny"){
        cout << "Чудовий день для пікніка" << endl;
    } else if (weather == "rainy")
    {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    } else if (weather == "cloudy"){
        cout << "Може, відвідати музей?" << endl;
    } else if (weather == "snowy"){
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if ( weather == "windy"){
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }
    
    cout << "Рекомендація щодо взуття: " << endl;
    switch (weather[0])
    {
    case 's':
    if (weather == "sunny")
    {
        cout << "Взуй улюблені кросівки" << endl;
    }else if (weather == "snowy")
    {
       cout << "Снігові черевики зігріють ваші ноги!" << endl;
    }
        break;
    case 'r':
       cout << "Дощові чоботи - гарна ідея!" << endl;
       break;
    case 'c':
       cout << "Сьогодні підходить будь-яке взуття." << endl;
       break;
    case 'w':
       cout << "Одягніть щось міцне!" << endl;
  
    default:
       break;
    }
    return 0;
}