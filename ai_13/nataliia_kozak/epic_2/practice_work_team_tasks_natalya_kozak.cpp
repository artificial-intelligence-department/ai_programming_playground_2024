#include <iostream>
#include <limits>

using namespace std;
int main(){
    int weather;
    while(true){
    cout << endl << "input type of weather:" << endl;
    cout << "1 - sunny, 2 - rainy, 3 - cloudy, 4 - snowy, 5 - windy"<< endl;
    cin >> weather; 
    // Check if input is valid
    if (cin.fail()) {
        cin.clear(); // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a number between 1 and 5." << endl;
        continue;
    }

    if (weather > 5 || weather <= 0) {
        cout << "Please enter a number between 1 and 5." << endl;
        continue;
    }
    //recommendation about jacket
    if (weather == 4 || weather == 2){
        cout << "wear a jacket!" << endl;
    }
    else{
        cout << "no nead to wear a jacket" << endl;
    }
    //recommendations about activity
    if (weather == 1){
        cout << "Perfect day for picnic" << endl;
    }
    else if (weather == 2){
        cout << "Perfect weather for reading inside" << endl;
    }
    else if (weather == 3){
        cout << "Maybe visit a museum?" << endl;
    }
    else if(weather == 4){
        cout << "How about making a snowman?" << endl;
    }
    else if(weather == 5){
        cout << "fly a kite if you have one" << endl;
    }
    //recommendations about footwear
    switch(weather){
        case 1:
            cout << "put on your favorite sneakers";
            break;
        case 2:
            cout << "rain boots are a good idea";
            break;
        case 3:
            cout << "any shoe is fine today";
            break;
        case 4:
            cout << "snow boots will keep your feet warm";
            break;
        case 5:
            cout << "wear something sturdy";
            break;
    }
    break;
    }
    return 0;
}