#include <stdio.h>
#include <iostream>

using namespace std;

int main () {

int weather = 0;

cout << "enter the weather option:\n" << "(1 for sunny, 2 for rainy, 3 for cloudy, 4 for snowy, 5 for windy)\n";



while (weather > 5 || weather < 1 ){
    cin >> weather;
    if (weather > 5 || weather < 1 ){
        cout << "Please entar a valid weather optioin!\n";
    }
}



if (weather == 2 || weather == 4){
    cout << "You should wear a jacket today!\n";
    }

 else {
    cout << "You won't need a jacket today!\n";
}



if (weather == 1){
    cout << "A great day for a picnic!\n";
}
else
    if (weather == 2){
        cout << "Better stay inside and read a book!\n";
}
else
    if (weather == 3){
        cout << "Maybe, you cold wisit a museum?\n";
}
else
    if (weather == 4){
        cout << "How about making a snowman?\n";
}
else
    if (weather == 5){
        cout << "You culd fly a kite, if you have one!\n";
}



switch (weather){
    case 1:
        cout << "Put your favourite pair of sneakers on!\n";
        break;

    case 2:
        cout << "Rain boots might be a great idea!\n";
        break;
    
    case 3:
        cout << "Any footwear will do today!\n";
        break;
    
    case 4:
        cout << "Snow boots will warm your legs!\n";
        break;
    
    case 5:
        cout << "Put something solid on!\n";
        break;
}

return 0;
}