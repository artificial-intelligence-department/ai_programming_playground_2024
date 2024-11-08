#include <iostream>
#include <string>
using namespace std;

int main() {
    
    cout << "What is the weather today? (sunny, windy, rainy, cloudy, snowy): ";
    string weather;
    cin >> weather;
     if (weather != "sunny" && weather != "windy" && weather != "rainy" && weather != "cloudy" && weather != "snowy")
 {
    cout << " Please return" << endl;
    return 1;
 }

    if (weather == "snowy" || weather == "rainy") {
        cout << "Please, wear a jacket." << endl;
    } 
    else 
    {
        cout << "You don't need a jacket." << endl;
    }

    if (weather == "sunny")
{
    cout << "A great day for a picnic!" << endl;
}
else if (weather == "rainy")
{
    cout << "Perfect weather to read a book within!" << endl;
}
else if (weather == "cloudy")
{
    cout << "Maybe visit a museum?" << endl;
}
else if (weather == "snowy")
{
    cout << "How about making a snowman?" << endl;
}
else if (weather == "windy")
{
    cout << "Launch the kite if it is in there are you!" << endl;   
}
switch (weather[1])
 {
        case 'u':
            cout << "Wear your favorite sneakers!" << endl;
            break;
        case 'n':
             cout << "Snow boots will keep your feet warm!" << endl;
            break;
        case 'a': 
            cout << "Rain boots are a good idea!" << endl;
            break;
        case 'l': 
            cout << "Today, any shoe is suitable." << endl;
            break;
        default:
            cout << "Wear something sturdy!" << endl;
            break;
      
    }

    return 0;
}