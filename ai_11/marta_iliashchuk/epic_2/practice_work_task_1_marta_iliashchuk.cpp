#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string your_weather;
    int a;
    cout<<"Введіть погоду (sunny,rainy,cloudy,snowy,windy): ";
    cin>> your_weather;

    if (your_weather == "rainy" or your_weather == "snowy"){
        cout<<"Візьміть куртку!";
    } 

    else{
         cout<<"Куртка не потрібна.";
    }

    if (your_weather == "sunny"){

        cout<<"Чудовий день для пікніка!";
        a = 1;
    } 

    else if(your_weather == "rainy"){
         cout<<"Ідеальна погода, щоб читати книгу всередині!";
         a = 2;
    }

    else if(your_weather == "cloudy"){
         cout<<"Може, відвідати музей?";
          a = 3;
    }

    else if(your_weather == "snowy"){
         cout<<"Як щодо того, щоб зліпити сніговика?";
          a = 4;
    }

     else if(your_weather == "windy"){
         cout<<"Запустіть повітряного змія, якщо він у вас є!";
          a = 5;
    }
    
    switch (a)
    {
     case 1:
     cout<<"Взуй улюблені кросівки!";
     break;

     case 2:
     cout<<"Дощові чоботи - гарна ідея!";
     break;

     case 3:
     cout<<"Сьогодні підходить будь-яке взуття.";
     break;

     case 4:
     cout<<"Снігові черевики зігріють ваші ноги!";
     break;
     
     case 5:
     cout<<"Одягніть щось міцне!";
     break;
    }

    return 0;
}