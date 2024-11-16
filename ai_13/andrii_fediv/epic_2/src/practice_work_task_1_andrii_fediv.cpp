#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main(){
    cout << "say your condition: ";
    string weather[] = {"sunny", "rainy", "cloudy", "snowy", "windy"};
    string pre_c;
    getline(cin, pre_c);
    istringstream ss(pre_c);
    string c;
    ss >> c;

    if(c == weather[0]){
        cout << "A great day for a picnic!\n";
    } else if(c == weather[1]){
        cout << "Perfect weather to read a book inside!\n";
    } else if(c == weather[2]){
        cout << "Maybe visit a museum?\n";
    } else if(c == weather[3]){
        cout << "How about making a snowman?\n";
    } else if(c == weather[4]){
        cout << "Fly a kite if you have one!\n";
    } else {
        return 0;
    }

    if(c == weather[1] || c == weather[3]){
        cout << "take a jacket\n";
    } else {
        cout << "you can go out without jacket\n";
    }
    int index = 0;
    for(string el: weather){
        if(c == el){
            break;
        }
        index++;
    }

    switch (index)
    {
    case 0:
        cout << "Wear your favorite sneakers!\n";
        break;

    case 1:
        cout << "Rain boots are a good idea!\n";
        break;

    case 2:
        cout << "Today, any shoe is suitable.\n";
        break;

    case 3:
        cout << "Snow boots will keep your feet warm!\n";
        break;

    case 4:
        cout << "Wear something sturdy!\n";
        break;
    
    default:
        break;
    }

    return 0;
}