#include<iostream>

using namespace std;

int main()
{
    string weather;
    int temp = 0;
    
    cout << "Введіть поточну погоду:\n sunny \n rainy \n cloudy \n snowy \n windy \n";
    cin >> weather;
    if(!(weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy")){
        cout << "Invalid output";
        return 0;
    };

    if(weather == "snowy" || weather == "rainy") {
        cout << "Вам краще одягнути куртку!" << endl;
    } else {
        cout << "Куртка сьогодні не знадобиться" << endl;
    };

    if(weather == "sunny"){
        temp = 1;
        cout << "Чудовий день для пікніка!" << endl;
    } else if(weather == "rainy"){
        temp = 2;
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    } else if (weather == "cloudy"){
        temp = 3;
        cout << "Може, відвідати музей?" << endl;
    } else if(weather == "snowy"){
        temp = 4;
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if(weather == "windy"){
        temp = 5;
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    };

    switch(temp){
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
    };
    
    return 0;
}