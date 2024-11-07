#include <iostream>
using namespace std;

int main() {
    string currentWeather, weatherOptions[5] = {"sunny", "rainy", "cloudy", "snowy", "windy"};
    int weatherIndex;

    //Ввід погоди, перевірка коректного вводу та перехід на індекс
    bool correct_input = false;
    while (!correct_input) {
        cout << "Enter weather: ";
        cin >> currentWeather;

        for (int i = 0; i < 5; i++) {
            if (currentWeather == weatherOptions[i]) {
                correct_input = true;
                weatherIndex = i;
                break;
            }
        }

        if (!correct_input) {
            cout << "\nWrong input, try one of these: ";
            for (int i = 0; i < 5; i++) {
                cout << weatherOptions[i];
                if (i != 4) cout << ", ";
            }
            cout << endl;
        }
    }

    //Рекомендації щодо куртки
    if (weatherIndex % 2 == 1) cout << "\nTake the jacket";
    else cout << "\nNo jacket required";

    //Рекомендації щодо дозвілля
    if (weatherIndex == 0) cout << "\nA great day for a picnic!";
    else if (weatherIndex == 1) cout << "\nPerfect weather to read a book inside!";
    else if (weatherIndex == 2)  cout << "\nMaybe visit a museum?";
    else if (weatherIndex == 3)  cout << "n\nHow about making a snowman?";
    else  cout << "\nFly a kite if you have one!";

    //Рекомендації щодо взуття
    switch(weatherIndex) {
        case 0:
            cout << "\nWear your favorite sneakers!";
            break;

        case 1:
            cout << "\nRain boots are a good idea!";
            break;

        case 2:
            cout << "\nToday, any shoe is suitable";
            break;

        case 3:
            cout << "\nSnow boots will keep your feet warm!";
            break;

        case 4:
            cout << "\nWear something sturdy!";
            break;
    }

    return 0;
}


