#include<iostream>
#include<string>
using namespace std;

int main()
{
    string weather;

    ///Введення вхідних даних та перевірка їх на коректність    
    cout<< "Оберіть сьогоднішню погоду: "<< endl;
    cout<<"-sunny"<<endl;
    cout<<"-rainy"<<endl;
    cout<<"-cloudy"<<endl;
    cout<<"-snowy"<<endl;
    cout<<"-windy"<<endl;
    cin >> weather;

    while (!((weather == "sunny") || (weather == "rainy") || (weather == "cloudy") || (weather == "snowy") || (weather == "windy")))
    {
        cout<<endl;
        cout<<"Введіть правильні вхідні дані"<<endl;
        cout<<"-sunny"<<endl;
        cout<<"-rainy"<<endl;
        cout<<"-cloudy"<<endl;
        cout<<"-snowy"<<endl;
        cout<<"-windy"<<endl;
        cin >> weather;
    }
    ///Введення вхідних даних та перевірка їх на коректність    

    ///Перевірка чи потрібна куртка
    if ((weather == "rainy") || (weather == "windy")) cout<<"Сьогодні краще одягнути куртку"<<endl;
    else cout<<"Сьогодні хороша погода, куртка вам не знадобиться"<<endl;
    ///Перевірка чи потрібна куртка

    ///Рекомендації чим сьогодні зайнятись
    int w = 0;
    if (weather == "sunny") 
    {
        cout<<"Чудовий день для пікніка!"<<endl;
        w = 1;
    }
    else if (weather == "rainy") 
    {
        cout<<"Ідеальна погода, щоб читати книгу всередині!"<<endl;
        w = 2;
    }
    else if (weather == "cloudy") 
    {
        cout<<"Може, відвідати музей?"<<endl;
        w = 3;
    }
    else if (weather == "snowy") 
    {
        cout<<"Як щодо того, щоб зліпити сніговика?"<<endl;
        w = 4;
    }
    else
    {
        cout<<"Запустіть повітряного змія, якщо він у вас є!"<<endl;
        w = 5;
    }
    ///Рекомендації чим сьогодні зайнятись

    ///Рекомендації що сьогодні взути
    switch (w)
    {
        case 1:
        {
            cout<<"Взуй улюблені кросівки!"<<endl;
            break;
        }
        case 2:
        {
            cout<<"Дощові чоботи - гарна ідея!"<<endl;
            break;
        }
        case 3:
        {
            cout<<"Сьогодні підходить будь-яке взуття."<<endl;
            break;
        }
        case 4:
        {
            cout<<"Снігові черевики зігріють ваші ноги!"<<endl;
            break;
        }
        case 5:
        {
            cout<<"Одягніть щось міцне!"<<endl;
            break;
        }
        
    }
    ///Рекомендації що сьогодні взути

    return 0;
}