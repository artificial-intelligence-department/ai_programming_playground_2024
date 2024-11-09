#include <iostream>

using namespace std;
int main()
{
    char weather;
    cout<<"Enter you current weather,it can be only \n s for sunny \n r for rainy \n c for cloudy \n S for snowy \n w for windy \n\n";
    cin>>weather;
     if (weather != 's' && weather != 'r' && weather != 'c' && weather != 'S' && weather != 'w') {
        cout << "Invalid input, try again";
        return 0;
    }
    if (weather == 'r' || weather == 'S'){
        cout<<"\nYou should wear a jacket\n";
    }
    else{
        cout<< "\nNo need for a jacket today\n";
    }
    if (weather == 's'){
        cout<<"\nA great day for a picnic!";
    }
        else if(weather == 'r'){
            cout<<"\nPerfect weather to read a book at home!\n";
        }
        else if(weather == 'c'){
            cout<<"\nMaybe visit a museum?\n";
        }
        else if(weather == 'S'){
            cout<<"\nHow about making a snowman?\n";
        }
        else if(weather == 'w'){
            cout<<"\nFly a kite if you have one!\n";
        }
    switch (weather){
        case 's': 
            cout<<"\nPut on your favorite sneakers!";
            break;
        case 'r': 
            cout<<"\nRain boots are a good idea!";
            break;
        case 'c': 
            cout<<"\nToday, any shoe is suitable.";
            break;
        case 'S': 
            cout<<"\n Snow boots will keep your feet warm!";
            break;
        case 'w': 
            cout<<"\nWear something sturdy!";
            break;
    }
    return 0;
}