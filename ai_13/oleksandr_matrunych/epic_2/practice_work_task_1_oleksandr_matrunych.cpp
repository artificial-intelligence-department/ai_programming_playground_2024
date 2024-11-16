#include <iostream>
using namespace std;

int main() {
    string weather;
    cout << "What's the weather like today? (options: sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    int weathertype = 0;

    if (weather == "snowy" || weather == "rainy") {
        cout << "You better wear a jacket!" << endl;
    } else if (weather == "sunny" || weather == "cloudy" || weather == "windy") {
        cout << "No need for a jacket today!" << endl;
    }

    if (weather == "sunny") {
        cout << "A great day for a picnic!" << endl;
        weathertype = 1;
    } 
    else if (weather == "rainy") {
        cout << "Perfect weather to read a book inside." << endl;
        weathertype = 2;
    } 
    else if (weather == "cloudy") {
        cout << "Maybe visit a museum?" << endl;
        weathertype = 3;
    } 
    else if (weather == "snowy") {
        cout << "How about making a snowman?" << endl;
        weathertype = 4;
    } 
    else if (weather == "windy") {
        cout << "Fly a kite if you have one!" << endl;
        weathertype = 5;
    } 
    else {
        cout << "You can't write properly" << endl;
        return 0;
    }

    cout << "Suggested footwear: ";
    switch (weathertype) {
        case 1:
            cout << "Put on your favorite sneakers!";
            break;
        case 2:
            cout << "Rain boots are a good idea!";
            break;
        case 3:
            cout << "Today, any shoes are suitable.";
            break;
        case 4:
            cout << "Snow boots will keep your feet warm!";
            break;
        case 5:
            cout << "Wear something sturdy!";
            break;
    }
    
    return 0;
}
