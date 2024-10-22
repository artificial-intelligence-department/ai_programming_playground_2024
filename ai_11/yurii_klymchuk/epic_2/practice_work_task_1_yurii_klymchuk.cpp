#include <iostream>

using namespace std;

void ClothingRecommendations(int weather){
    if (weather == 2 || weather == 4){
        cout << "You should put your jacket on." << endl;
    }
    else {
        cout << "Jacket isn`t necessary." << endl;
    }
} 

void ActivitiesRecommendations(int weather){
    if (weather == 1){
        cout << "A great day for a picnic" << endl;
    }
    else if (weather == 2){
        cout << "Perfect weather to read a book inside!" << endl;
    }
    else if (weather == 3){
        cout << "Maybe visit a museum" << endl;
    }
    else if (weather == 4){
        cout << "How about making a snowman?" << endl;
    }
    else if (weather == 5){
        cout << "Fly a kite if you have one!" << endl;
    }
}

void ShoesRecommendations(int weather){
    switch (weather)
    {
    case 1:
        cout << "Put on your favorite sneakers!";
        break;
    case 2:
        cout << "Rain boots are a good idea!";
        break;
    case 3:
        cout << "Today, any shoe is suitable";
        break;
    case 4:
        cout << "Snow boots will keep your feet warm!";
        break;
    case 5:
        cout << "Wear something sturdy!";
        break;
    }
} 

int main(){
    int weather;

    cout << "Enter one of possible weather conditions: " <<
    "\n1: sunny" <<
    "\n2: rainy" <<
    "\n3: cloudy" <<
    "\n4: snowy" << 
    "\n5: windy" << endl;
    cin >> weather;

    switch (weather)
    {
    case 1:
        cout << "The weather is sunny";
        break;
    case 2:
        cout << "The weather is rainy";
        break;
    case 3:
        cout << "The weather is cloudy";
        break;
    case 4:
        cout << "The weather is snowy";
        break;
    case 5:
        cout << "The weather is windy";
        break;
    default:
        cout << "Your weather condition isn`t on the list";
        return 0;
    }

    cout << "\n\nСlothing recommendations:"<< endl;
    ClothingRecommendations(weather);

    cout << "\nActivities recommendations:" << endl;
    ActivitiesRecommendations(weather);

    cout << "\nShoes recommendations:" << endl;
    ShoesRecommendations(weather);
    
    return 0;
}