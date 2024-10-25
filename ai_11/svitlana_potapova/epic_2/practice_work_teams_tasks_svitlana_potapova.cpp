#include <iostream>
using namespace std; 

int main(){
    string weather;
    int shoes_choice;
    cout << "Enter the weather(sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    if(weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy"){
        cout << "Invalid input";
        return 0;
    }

    cout << "Чи брати куртку? " << endl;
    if (weather == "rainy" || weather == "snowy"){
        cout << "Так" << endl;
    }
    else{
        cout << "Ні" << endl;
    }

    cout << "Рекомендація щодо активності: " << endl;
    if (weather == "sunny"){
        cout << "Чудовий день для пікніка!" << endl;
        shoes_choice = 1;
    }
    else if (weather == "rainy"){
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
        shoes_choice = 2;
    }
    else if (weather == "cloudy"){
        cout << "Може, відвідати музей?" << endl;
        shoes_choice = 3;
    }
    else if (weather == "snowy"){
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
        shoes_choice = 4;
    }
    else if (weather == "windy"){
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
        shoes_choice = 5;
    }

    cout << "Рекомендації щодо взуття: " << endl;
    switch(shoes_choice){
        case 1:
         cout << "Взуй улюблені кросівки!";
         break;
        case 2:
         cout << "Дощові чоботи - гарна ідея!";
         break;
        case 3:
         cout << "Сьогодні підходить будь-яке взуття";
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