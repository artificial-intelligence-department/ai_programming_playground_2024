#include"iostream"
using namespace std;
int main(){
    int n_weather;
    string weather;
    cin >> weather;

    enum Weather{
        sunny,
        rainy,
        cloudy,
        snowy, 
        windy
    };


    //Рішення чи брати куртку
    if(weather == "snowy" || weather == "rainy"){
        cout << "Put on a jacket\n";
    }
    else{
        cout << "You don`t need a jacket\n";
    }

    //Рекомендація щодо активності (використання if, else if)
    if(weather == "sunny"){
        cout << "It is a great day for a picnic!\n";
        n_weather = 0;
    }
    else if(weather == "rainy"){
        cout << "It is an ideal day for reading a book indoor!\n";
        n_weather = 1;
    }
    else if(weather == "cloudy"){
        cout << "Maybe you should visit a museum?\n";
        n_weather = 2;
    }    
    else if(weather == "snowy"){
        cout << "Don`t you mind making a snowman?\n";
        n_weather = 3;
    }
    else if(weather == "windy"){
        cout << "Fly a kite if you have one!\n";
        n_weather = 4;
    }
    
    
    //Рекомендації щодо взуття  
    switch(n_weather){
        case sunny:
            cout << "Put on your favorite sneakers!\n";
            break;
        case rainy:
            cout << "Rain boots are a good idea!\n";
            break;
        case cloudy:
            cout << "Today, any shoe is suitable.\n";
            break;
        case snowy:
            cout << "Snow boots will keep your feet warm!\n";
            break;
        case windy:
            cout << "Wear something sturdy!\n";
            break;
    }

    return 0;
}