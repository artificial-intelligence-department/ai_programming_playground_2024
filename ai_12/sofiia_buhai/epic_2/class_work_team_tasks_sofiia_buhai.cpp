#include <iostream>
using namespace std;

int main() {
    int wType;  // змінна для подальшоко використовування switch
    string weather;     //змінна для вводу погоди
    cout << "Яка погода зараз надворі? Прошу вибрати одну з наступних відповідей : \n sunny \n rainy \n cloudy \n snowy \n windy \n ------ \n\n" ;
    cin >> weather;
    // перевірка вводу погоди
    if(weather!="sunny" && weather!="rainy" && weather!="cloudy" && weather!="snowy" && weather!="windy") {
        do {
            cout << "Неправильно введена погода, введіть ще раз :";
            cin >> weather;
        } while (!(weather=="sunny" || weather=="rainy" || weather=="cloudy" || weather=="snowy" || weather=="windy"));
    }
    // перевірка для куртки
    if ( weather=="snowy" || weather=="rainy" ) {
        cout << "Одягніть курточку!\n";
    } else {
        cout << "Вам куртка не потрібна.\n";
    }
    // перевірка для активностей
    if (weather=="sunny") {
        cout << "Чудовий день для пікніка!\n";
        wType = 0;
    } else { if(weather=="rainy"){
        cout << "Ідеальна погода, щоб почитати книгу всередині!\n";
        wType = 1;
    } else { if(weather=="cloudy"){
        cout << "Може, відвідати музей?\n";
        wType = 2;
    } else {if(weather=="snowy"){
        cout << "Як щодо того, щоб зліпити сніговика?\n";
        wType = 3;
    } else {
        cout << "Запустіть повітряного змія, якщо він у вас є!\n";
        wType = 4;
    }}}}
    // перевірка для взуття
    switch(wType){
        case 0 :
           cout << "Взуй улюблені кросівки!\n";
           break;
        case 1 :
           cout << "Дощові чоботи - гарна ідея!\n";
           break;
        case 2 :
           cout << "Сьогодні підходить будь-яке взуття.\n";
           break;
        case 3 :
           cout << "Снігові черевики зігріють ваші ноги!\n";
           break;
        case 4 :
           cout << "Одягніть щось міцне!\n";
           break;
    }
}