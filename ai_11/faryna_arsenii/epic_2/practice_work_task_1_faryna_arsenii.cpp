#include <iostream>

using namespace std;

int main(){
    int choice;

    cout << "Write weather condition\n";
    cout << "Possible weather condition\n";
    cout << "1. sunny" << endl;
    cout << "2. rainy" << endl;
    cout << "3. cloudy" << endl;
    cout << "4. snowy" << endl;
    cout << "5. windy" << endl;
    cout << "Input number: ";
    cin >> choice;

    switch (choice){
        case 1: 
            cout << "You choose sunny\n";
            break;
        case 2: 
            cout << "You choose rainy\n";
            break;
        case 3: 
            cout << "You choose cloudy\n";
            break;
        case 4: 
            cout << "You choose snowy\n";
            break;
        case 5: 
            cout << "You choose windy\n";
            break;
        default:
            cout << "Choice is wrong\n";
    }

    //recomendation for jacket

    cout << "How about jacket?" << endl;

    if (choice == 2, 4){
        cout << "You should wear jacket" << endl;
    }
    else{
        cout << "Jacket is not required" << endl;
    }
    
    //recomendation for activity
    
    cout << "How about activity" << endl;

    if (choice == 1){
        cout << "It's a great opportunity to go on a picnic with friends" << endl;
    }
    else if(choice == 2){
        cout << "Perfect weather to read a book inside!" << endl;
    }
    else if(choice == 3){
        cout << "Maybe you can visit the museum?" << endl;
    }
    else if(choice == 4){
        cout << "How about making a snowman?" << endl;
    }
    else if(choice == 5){
        cout << "Launch the kite if you have one!" << endl;
    }
    
    //recomendation for footwear
    
    cout << "How about shoes?" << endl;

    switch (choice){
        case 1: 
            cout << "Wear your favorite sneakers!";
            break;
        case 2: 
            cout << "Rain boots are a good idea!";
            break;
        case 3: 
            cout << "Any shoes fit today!";
            break;
        case 4: 
            cout << "Snow boots will warm your feet!";
            break;
        case 5: 
            cout << "Put on something strong!";
            break;
    }
    return 0;
}