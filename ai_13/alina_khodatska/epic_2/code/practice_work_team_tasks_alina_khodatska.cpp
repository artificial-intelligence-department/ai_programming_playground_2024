#include <iostream>
#include <string>

int main() {
    std::string weather;

    std::cout << "Enter the current weather (sunny, rainy, cloudy, snowy, windy): ";
    std::cin >> weather;

    if (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy") {
        std::cout << "Please enter a valid weather condition." << std::endl;
        return 1;
    }

    if (weather == "snowy" || weather == "rainy") {
        std::cout << "You should wear a jacket." << std::endl;
    }
    else {
        std::cout << "No need for a jacket today." << std::endl;
    }

    if (weather == "sunny") {
        std::cout << "A great day for a picnic!" << std::endl;
    }
    else if (weather == "rainy") {
        std::cout << "Perfect weather to read a book inside!" << std::endl;
    }
    else if (weather == "cloudy") {
        std::cout << "Maybe visit the museum?" << std::endl;
    }
    else if (weather == "snowy") {
        std::cout << "How about making a snowman?" << std::endl;
    }
    else if (weather == "windy") {
        std::cout << "Launch the kite if you have it!" << std::endl;
    }

    std::cout << "Recommended footwear: ";
    switch (weather[0]) {
    case 's':
        if (weather == "sunny") {
            std::cout << "Wear your favorite sneakers!" << std::endl;
        }
        else if (weather == "snowy") {
            std::cout << "Snow boots will warm your feet!" << std::endl;
        }
        break;
    case 'r':
        std::cout << "Rain boots are a good idea!" << std::endl;
        break;
    case 'c':
        std::cout << "Any shoe fits today." << std::endl;
        break;
    case 'w':
        std::cout << "Put on something strong!" << std::endl;
        break;
    default:
        std::cout << "Please enter a valid weather condition." << std::endl;
    }

    return 0;
}
