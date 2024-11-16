#include <iostream>
#include <string>
using namespace std;

enum whichw {
        sunny,
        rainy,
        cloudy,
        snowy,
        windy,
    };

whichw ww(string w){
    if(w == "sunny"){
        return sunny;
    }
    if(w == "rainy"){
        return rainy;
    }
    if(w == "cloudy"){
        return cloudy;
    }
    if(w == "snowy"){
        return snowy;
    }
    if(w == "windy"){
        return windy;
    }
    return sunny;
}

void cpog(whichw weath){

    switch(weath)
    {
        case sunny:
            cout << "wear favourite shoes";
            break;
        case rainy:
            cout <<"Rain boots are a good idea!";
            break;
        case cloudy:
            cout <<"you can wear anything";
            break;
        case snowy:
            cout <<"Snow boots will keep your feet warm!";
            break;        
        case windy:
            cout <<"Put on something strong!";
            break;
    }
}



int main() {
    
    string weather;


    cout << "What's the weather like today?" << endl;
    getline(cin,weather);
    while((weather != "sunny") && (weather != "rainy") && (weather != "cloudy") && (weather != "windy") && (weather == "snowy")){
        cout << "please try again and make it right: ";
        getline(cin,weather);
    }

    




    if(weather == "snowy" || weather == "rainy"){
        cout << "you should wear coat" << endl;
    }
    else {
        cout << "you don't need coat today" << endl;
    }
    if(weather == "sunny"){
        cout << "this is a great day for a picnic" << endl;
    }
    else if(weather == "rainy"){
        cout << "Perfect weather for reading inside" << endl;
    }
    else if(weather == "snowy"){
        cout << "what about making a snowman?" << endl;
    }
    else if(weather == "windy" ){
        cout << "fly the kite if you have one" << endl;
    }

    whichw wet = ww(weather);
    cpog(wet);

    return 0;
}