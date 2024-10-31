#include <iostream>
using namespace std;

int main(){
    string condition;
    cout << "What are the weather conditions today?" << endl;
    cin >> condition;

    if (condition == "rainy" || condition == "snowy"){
        cout << "Put on a jacket" << endl;
    } else {
        cout << "You don`t need a jacket" << endl;
    }

    int index;

    if (condition == "sunny"){
        cout << "Great day for a picnic!" << endl;
        index = 0;
    } else if (condition == "rainy"){
        cout << "Perfect weather to read a book inside" << endl;
        index = 1;
    } else if (condition == "cloudy"){
        cout << "Maybe, you shoud visit a museum?" << endl;
        index = 2;
    } else if (condition == "snowy"){
        cout << "How about making a snowman?" << endl;
        index = 3;
    } else if (condition == "windy"){
        cout << "Fly a kite, if you have one!" << endl;
        index = 4;
    }

    switch (index) {
        case 0:
            cout << "Wear your favourite sneakers!";
            break;
        case 1:
            cout << "Rain boots are a good idea!";
            break;
        case 2:
            cout << "Any pair of shoes is suitable today";
            break;
        case 3:
            cout << "Snow boots will warm your toes";
            break;
        case 4:
            cout << "Wear something sturdy!";
            break;
        default:
            cout << "Error";
    }


    return 0;
}