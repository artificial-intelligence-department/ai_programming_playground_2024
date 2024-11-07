#include <iostream>
#include <string>

using namespace std;

int main(){

    int condition;
    string weather;
    cout << "What is weather like today? (sunny, rainy, cloudy, snowy, windy )" ;
    cin >> weather;

    if ( weather == "sunny"  ||  weather == "rainy"  || weather == "cloudy"  || weather == "snowy"  || weather == "windy" ){
        
        if (weather == "rainy"  || weather == "snowy"){
            cout << "You should wear a coat!" << endl;
        } else {
            cout << "Today you can go without a coat!" << endl;
        }


        if (weather == "sunny"){
            cout << "It's a good day for picnic!" << endl;
            condition = 1;
        } else if (weather == "rainy"){
            cout << "It would be great to read a book at home!" << endl;
            condition = 2;
        }else if (weather == "cloudy"){
            cout << "Maybe visit a museum?" << endl;
            condition = 3;
        }else if (weather == "snowy"){
            cout << "How about making a snowman?" << endl;
            condition = 4;
        }else if (weather == "windy"){
            cout << "If you have a kite you can fly it!" << endl;
            condition = 5;
        }


        switch (condition){
            case 1 :
                cout << "You can put on your favourite sneakers!" << endl;
                break;
            case 2 :
                cout << "Rain boots are a great idea!" << endl;
                break; 
            case 3 :
                cout << "You can wear any shoes!" << endl;
                break;
            case 4 :
                cout << "You can wear your warm shoes!" << endl;
                break;
            case 5 :
                cout << "You can wear any shoes!" << endl;
                break;
            default :
                break;                   
        }

    } else {
        cout << "You have entered incorrect weather " << endl;
    }

    return 0;
}
