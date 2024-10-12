#include <iostream>
using namespace std;
int main(){
    string weather;
    cout<<"Яка зараз погода? ";
    cin >> weather;
    if(weather=="snowy"|| weather=="rainy"||weather=="sunny"||weather=="windy"||weather=="cloudy"){
        cout<<"Чи одягати куртку? ";
            if (weather=="snowy"|| weather== "rainy"){
                cout<<"Так";
            }
                else cout<<"Ні";
            cout<<endl<<"Рекомендована активність. ";
                if (weather=="sunny"){cout<<"Чудовий день для пікніка";}
                else if (weather=="rainy"){cout<<"Ідеальна погода, щоб читати книгу всередині!";}
                else if (weather=="cloudy"){cout<<"Може, відвідати музей?";}
                else if (weather=="snowy"){cout<<"Як щодо того, щоб зліпити сніговика?";}
                else if (weather=="windy"){cout<<"Запустіть повітряного змія, якщо він у вас є!";}
        cout<<endl<<"Рекомендації щодо взуття. ";
            int x;
            if (weather=="sunny"){x=1;}
            if (weather=="rainy"){x=2;}
            if (weather=="cloudy"){x=3;}
            if (weather=="snowy"){x=4;}
            else if (weather=="windy"){x=5;}
            switch(x){
            case 1: cout<<"Взуй улюблені кросівки!"; break;
            case 2: cout<<"Дощові чоботи - гарна ідея!";break;
            case 3: cout<<"Сьогодні підходить будь-яке взуття.";break;
            case 4: cout<<"Снігові черевики зігріють ваші ноги!";break;
            case 5: cout<<"Одягніть щось міцне!";break;
        }
    }
    else cout<<"Введіть дійсне значення погоди";
    return 0;
}