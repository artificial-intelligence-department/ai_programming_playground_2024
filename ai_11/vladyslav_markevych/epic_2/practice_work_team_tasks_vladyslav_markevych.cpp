#include <iostream>

using namespace std;

int main()
{
    int weather;
    cout<<"Choose weather (1-rainy,2-snowy,3-cloudy,4-sunny,5-windy)"<<endl;
    cin>>weather;

if(weather<=2)
{
    cout<<"Одягніть куртку!"<<endl;
}else{
    cout<<"Можливо обійтись без куртки!"<<endl;
}


if (weather==4)
{
    cout<<"Чудовий день для пікніка!"<<endl;
}else if(weather==1){
    cout<<"Ідеальна погода, щоб читати книгу всередині!"<<endl;
}else if (weather==3)
{
    cout<<"Може, відвідати музей?"<<endl;
}else if(weather==2){
    cout<<"Як щодо того, щоб зліпити сніговика?"<<endl;
}else if (weather==5)
{
    cout<<"Запустіть повітряного змія, якщо він у вас є!"<<endl;
}


    switch (weather){
    case 1:
        cout<<"Дощові чоботи - гарна ідея"<<endl;;
        break;
    case 2:
        cout<<"Снігові черевики зігріють ваші ноги!"<<endl;
        break;
    case 3:
        cout<<"Сьогодні підходить будь-яке взуття."<<endl;
        break;
    case 4:
        cout<<"Взуй улюблені кросівки!"<<endl;;
        break;
    case 5:
        cout<< "Одягніть щось міцне!"<<endl;
        break;
    }
return 0;
}