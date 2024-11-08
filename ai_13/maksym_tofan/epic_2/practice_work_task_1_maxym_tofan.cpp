#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    cout << "Say your condition: ";
    string weather[] = {"sunny", "rainy", "cloudy", "snowy", "windy"};
    string input;
    getline(cin, input);
    
    int index = -1;
    for (int i = 0; i < 5; i++) {
        if (input.find(weather[i]) != string::npos) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Unknown weather condition.\n";
        return 0;
    }

    switch (index) {
        case 0: cout << "A great day for a picnic!\n"; break;
        case 1: cout << "Perfect weather to read a book inside!\n"; break;
        case 2: cout << "Maybe visit a museum?\n"; break;
        case 3: cout << "How about making a snowman?\n"; break;
        case 4: cout << "Fly a kite if you have one!\n"; break;
    }

    cout << ((index == 1 || index == 3) ? "Take a jacket\n" : "You can go out without a jacket\n");

    switch (index) {
        case 0: cout << "Wear your favorite sneakers!\n"; break;
        case 1: cout << "Rain boots are a good idea!\n"; break;
        case 2: cout << "Today, any shoe is suitable.\n"; break;
        case 3: cout << "Snow boots will keep your feet warm!\n"; break;
        case 4: cout << "Wear something sturdy!\n"; break;
    }

    return 0;
}
