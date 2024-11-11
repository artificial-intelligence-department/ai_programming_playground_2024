#include <iostream> 
using namespace std;

bool isElementAvalbl(const string constArr[], int size, const string constEl) {
    for(int i=0; i < size; i++){
        if (constArr[i] == constEl ) {
            return true;
        } 
    }
    return false;
}

void startProgram(){

string weather[5]= {"sunny","rainy","cloudy","snowy","windy"};
string consWeather[2] = {weather[1], weather[3]};
string userWeather;
int weatherCode = 0;


    cout << "Write one of weather types:" << endl;
    for(int i=0; i < 5; i++) { 
        cout << weather[i] << endl ;
    }
    cin >> userWeather;
    if (isElementAvalbl(weather, 5, userWeather)) {
        cout << "You entered a valid weather type" << endl;
    } else {
        cout << "You entered an invalid weather type, try again" << endl;
        startProgram();
    }

    if(isElementAvalbl(consWeather, 2, userWeather)){
        cout << "You must wear jacket" << endl;
    } else {
        cout << "Jacket isnt necessary" << endl;
    }
// sunny: "A perfect day for a picnic!"
// rainy: "Ideal weather to read a book indoors!"
// cloudy: "Maybe visit a museum?"
// snowy: "How about building a snowman?"
// windy: "Fly a kite if you have one!"
    if (userWeather == "sunny"){
        cout << "A perfect day for a picnic!" << endl;
    } else if (userWeather == "rainy"){
        cout << "Ideal weather to read a book indoors!" << endl;
    } else if (userWeather == "cloudy"){
        cout << "Maybe visit a museum?" << endl;
    }else if (userWeather == "snowy"){
        cout << "How about building a snowman?" << endl;
    }else if (userWeather == "windy"){
        cout << "Fly a kite if you have one!" << endl;
    }
// sunny: "Wear your favorite sneakers!"
// rainy: "Rain boots are a good idea!"
// cloudy: "Any shoes will do today."
// snowy: "Snow boots will keep your feet warm!"
// windy: "Wear something sturdy!"
    if (userWeather == "sunny") {
        weatherCode = 1;
    } else if (userWeather == "rainy") {
        weatherCode = 2;
    } else if (userWeather == "cloudy") {
        weatherCode = 3;
    } else if (userWeather == "snowy") {
        weatherCode = 4;
    } else if (userWeather == "windy") {
        weatherCode = 5;
    }

    switch (weatherCode) {
        case 1:
            cout << "Wear your favorite sneakers!" << endl;
            break;
        case 2:
            cout << "Rain boots are a good idea!" << endl;
            break;
        case 3:
            cout << "Any shoes will do today." << endl;
            break;
        case 4:
            cout << "Snow boots will keep your feet warm!" << endl;
            break;
        case 5:
            cout << "Wear something sturdy!" << endl;
            break;
        default:
            cout << "No specific shoe recommendation for this weather." << endl;
    }
}



int main(){
    startProgram();
    return 0;
}