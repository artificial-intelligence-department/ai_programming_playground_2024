#include <iostream>
enum class WeatherCondition {
    sunny,
    rainy,
    cloudy,
    snowy,
    windy,
    unknown
};

WeatherCondition getWeatherCondition(const std::string& input) {
    if (input == "sunny") {
        return WeatherCondition::sunny;
    } else if (input == "rainy") {
        return WeatherCondition::rainy;
    } else if (input == "cloudy") {
        return WeatherCondition::cloudy;
    } else if (input == "snowy") {
        return WeatherCondition::snowy;
    } else if (input == "windy") {
        return WeatherCondition::windy;
    } else {
        return WeatherCondition::unknown;
    }
}

int main(){
    std::string weather;
    std::cout << "Enter weather condition(sunny, rainy, cloudy, snowy, windy): ";
    std::cin >> weather;
    if(weather == "rainy" || weather == "snowy") std::cout << "Take the jacket\n";
    if(weather == "sunny") std::cout << "Good day for a picnic\n";
    else if(weather == "rainy") std::cout << "Nice weather to read book in home\n";
    else if(weather == "cloudy") std::cout << "Maybe you should visit a musuem\n";
    else if(weather == "snowy") std::cout << "How aboout making a snowman\n";
    else if(weather == "windy") std::cout << "Fly a kite if you have one\n";
    WeatherCondition condition = getWeatherCondition(weather);
     switch (condition) {
        case WeatherCondition::sunny:
            std::cout << "Wear your favorite sneakers" << std::endl;
            break;
        case WeatherCondition::rainy:
            std::cout << "Rain boots are a good idea" << std::endl;
            break;
        case WeatherCondition::cloudy:
            std::cout << "Any footwear works today" << std::endl;
            break;
        case WeatherCondition::snowy:
            std::cout << "Snow boots will keep your feet warm" << std::endl;
            break;
        case WeatherCondition::windy:
            std::cout << "Wear something sturdy" << std::endl;
            break;
        default:
            std::cout << "Unknown weather condition! Choose footwear accordingly" << std::endl;
            break;
    }
    return 0;
}