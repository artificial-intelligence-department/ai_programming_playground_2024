#include <iostream>
#include <string>

using namespace std;

int main()
{
    string weather;
    int a;
    while (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy"){
        cout << "Введіть: sunny, rainy, cloudy, snowy або windy: ";
        cin >> weather;
    }
    
    if (weather == "rainy" || weather == "snowy"){
        cout << "Треба одягнути куртку."<< endl;
    }else{
       cout << "Куртка не потрібна."<< endl;
    }
    cout << "Рекомендація щодо активності: " << endl;
    if (weather == "sunny"){
        cout << "Чудовий день для пікніка! "<< endl;
        a = 1;
    }else if (weather == "rainy"){
        cout << "Ідеальна погода, щоб читати книгу всередині! "<< endl;
        a = 2;
    }else if (weather == "cloudy"){
        cout << "Може, відвідати музей? "<< endl;
        a = 3;
    }else if (weather == "snowy"){
        cout << "Як щодо того, щоб зліпити сніговика? "<< endl;
        a = 4;
    }else if (weather == "windy"){
        cout << "Запустіть повітряного змія, якщо він у вас є! "<< endl;
        a = 5;
    }
    cout << "Рекомендація щодо взуття: " << endl;
    switch (a){
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
            cout << "Одягніть щось міцне";
            break;      
    }
    return 0;
}