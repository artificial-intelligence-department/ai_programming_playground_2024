#include <iostream>

using namespace std;

int main(){
    char weather;

    cout << "Enter: s-sunny, r-rainy, c-cloudy, S-snowy, w-windy:" << endl;
    cin >> weather;


    switch (weather) {
    case 's':
    case 'r':
    case 'c':
    case 'S':
    case 'w':
        break;
    default: // same as else
        cout << "Try again" << endl;
        return 0;
}
    
    if(weather == 'r' || weather == 'S' ){
        cout << "You should wear coat!" << endl;
    }else cout << "You don`t need coat:)" << endl;
    
    
    if(weather=='s'){
        cout << "It`s a great idea to make a picnic!" << endl;
    } 
        else if(weather=='r'){ 
            cout << "It`s a great idea to read a book at home." << endl;
        }
        else if(weather=='c'){ 
            cout << "How about vising museum?" << endl;
        }
        else if(weather=='S'){   
            cout << "How about making a snowman?" << endl;
        }
        else if(weather=='w'){   
            cout << "How about flying kite?" << endl;
        }
    

    cout << "Clothing tips: "; 
    switch (weather) {
    case 's':
        cout << "Wear your favorite sneakers! \n";
        break;
    case 'r':
        cout << "Rain boots are a good idea! \n";
        break;
    case 'c':
        cout << "Today, any shoe is suitable. \n";
        break;
    case 'S':
        cout << "Snow boots will keep your feet warm! \n";
        break;
    case 'w':
     cout << "Wear something sturdy! \n";
        break;  
}

    return 0;
}
