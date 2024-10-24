#include <iostream>

using namespace std;

int main(){
    string weather;
    int weath;
    cin >> weather;

    if (weather == "sunny"){cout << "A great day for a picnic!" << endl; weath = 0;}
    else if (weather == "rainy") {cout << "Perfect weather to read a book inside!" << endl; weath = 1;}
    else if (weather == "cloudy") {cout << "Maybe visit a museum?" << endl; weath = 2;}
    else if (weather == "snowy") {cout << "How about making a snowman?" << endl; weath = 3;}
    else if (weather == "windy") {cout << "Fly a kite if you have one!" << endl; weath = 4;}
    else {return 1;}

    if (weather == "snowy" || weather == "rainy"){
        cout << "Put on a jacket" << endl;
    }
    else {cout << "No jacket required" << endl;}

    switch (weath) {
    case 0:
        cout << "Wear your favorite sneakers!" << endl;
        break;
    case 1:
        cout << "Rain boots are a good idea!" << endl;
        break;
    case 2:
        cout << "Today, any shoe is suitable." << endl;
        break;
    case 3:
        cout << "Snow boots will keep your feet warm!" << endl;
        break;
    case 4:
        cout << "Wear something sturdy!" << endl;
        break;
    default:
    break;
}
}