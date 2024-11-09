#include <iostream>
using namespace std;

int main() {
    string option;
    int shoes=0;

    cout<<"type weather conditions (sunny, rainy, cloudy, snowy, windy)"; //вибір
    cin>>option;

    if (option=="rainy" || option=="snowy"){ //куртка
        cout<<"You need a jacket for a walk!\n";
    }
    else{
        cout<<"You don't need a jacket for a walk!\n";
    }
    
    if (option=="sunny"){ //рекомедація активності
        cout<<"A wonderful day for a picnic!";
        shoes=1;
    }
    else if (option=="rainy"){
        cout<<"Perfect weather to read a book inside!";
        shoes=2;
    }
    else if (option=="cloudy"){
        cout<<"Maybe visit a museum?";
        shoes=3;
    }
    else if (option=="snowy"){
        cout<<"How about making a snowman?";
        shoes=4;
    }
    else if (option=="windy"){
        cout<<"Fly a kite if you have one!";
        shoes=5;
    }

    switch (shoes)
    {
    case 1:
        cout<<"Wear your favorite sneakers!";
        break;
    case 2:
        cout<<"Rain boots are a good idea!";
        break;
    case 3:
        cout<<"Today, any shoe is suitable.";
        break;
    case 4:
        cout<<"Snow boots will keep your feet warm!";
        break;
    case 5:
        cout<<"Wear something sturdy!";
        break;
    default:
        break;
    }
    return 0;
}