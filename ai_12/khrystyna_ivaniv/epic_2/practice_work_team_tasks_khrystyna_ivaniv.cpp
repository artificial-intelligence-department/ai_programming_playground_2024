#include <iostream>

using namespace std;

int main(){

    string weather;
    cout << "What's the weather like today?" << endl;
    cin >> weather;
    if(weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy"){
        if(weather == "rainy" || weather == "snowy"){
            cout << "You better wear a jacket!";
        }
        else {
            cout << "You do not need a jacket today!";
        }
        cout << endl;

        if(weather == "sunny"){
            cout << "A great day for a picnic!";
        }
        else if (weather == "rainy"){
            cout << "Perfect weather to read a book inside!";
        }
        else if (weather == "cloudy"){
            cout << "Maybe visit a museum?";
        }
        else if (weather == "snowy"){
            cout << "How about making a snowman?";
        }
        else if (weather == "windy"){
            cout << "Fly a kite if you have one!";
        }
        cout << endl;

        int weathertype;
        
        if(weather == "sunny"){
            weathertype = 1;
        }
        else if (weather == "rainy"){
            weathertype = 2;
        }
        else if (weather == "cloudy"){
            weathertype = 3;
        }
        else if (weather == "snowy"){
            weathertype = 4;
        }
        else if (weather == "windy"){
            weathertype = 5;
        }
        
        switch (weathertype) {
            case 1: cout <<"Put on your favorite sneakers!";
            break;
            case 2: cout <<"Rain boots are a good idea!";
            break;
            case 3: cout <<"Today, any shoes are suitable";
            break;
            case 4: cout <<"Snow boots will keep your feet warm!";
            break;
            case 5: cout <<"Wear something sturdy!";
            break;
             }

    }

    else {
        cout << "Enter another type of weather(options: sunny, rainy, cloudy, snowy, windy)";
    }
    
    return 0;
}