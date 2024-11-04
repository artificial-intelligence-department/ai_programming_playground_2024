#include <iostream>
#include <cstring>
using namespace std;

enum WeatherCondition {
    SUNNY,
    RAINY,
    WINDY,
    CLOUDY,
    SNOWY,
    INVALID
};

WeatherCondition getWeatherCondition(const char* cond) {
    if (strcmp(cond, "sunny") == 0) return SUNNY;
    if (strcmp(cond, "rainy") == 0) return RAINY;
    if (strcmp(cond, "windy") == 0) return WINDY;
    if (strcmp(cond, "cloudy") == 0) return CLOUDY;
    if (strcmp(cond, "snowy") == 0) return SNOWY;
    return INVALID;
}

int main() {
    cout << "Enter the current weather condition (sunny/rainy/windy/cloudy/snowy): ";
    char cond[10];
    cin.getline(cond, 10);

    WeatherCondition condition = getWeatherCondition(cond);

    if (condition == INVALID) {
        cout << "Try to enter a valid condition!" << endl;
        return 1; 
    }

    
    if (condition == RAINY || condition == SNOWY) {
        cout << "You should be wearing a coat today." << endl;
    } else {
        cout << "There's no need to wear a coat." << endl;
    }

    
    if (condition == SUNNY) {
        cout << "It's an amazing day for a picnic!" << endl;
    } else if (condition == RAINY) {
        cout << "How about staying inside and reading a good book?" << endl;
    } else if (condition == CLOUDY) {
        cout << "Visiting a museum would be a great idea." << endl;
    } else if (condition == SNOWY) {
        cout << "What a great chance to make your own snowman!" << endl;
    } else if (condition == WINDY) {
        cout << "If you have a kite, it's the perfect day to fly it!" << endl;
    }

    
    switch (condition) {
        case SUNNY:
            cout << "Wear your favorite sneakers." << endl;
            break;
        case RAINY:
            cout << "Rain boots are perfect for today." << endl;
            break;
        case CLOUDY:
            cout << "Any shoes are suitable today." << endl;
            break;
        case SNOWY:
            cout << "Snow boots will keep your feet warm!" << endl;
            break;
        case WINDY:
            cout << "Wear something durable to withstand the wind." << endl;
            break;
        default:
            break;
    }

    return 0;
}
