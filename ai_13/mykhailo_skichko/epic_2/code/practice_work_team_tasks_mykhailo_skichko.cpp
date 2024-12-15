#include <iostream>
#include <string>

int main()
{
    std::string weather;

    std::cout << "Enter the current weather (sunny, rainy, cloudy, snowy, windy): ";
    std::cin >> weather;

    if (weather == "rainy" || weather == "snowy")
    {
        std::cout << "You should take a jacket." << std::endl;
    }
    else
    {
        std::cout << "A jacket is not necessary." << std::endl;
    }

    if (weather == "sunny")
    {
        std::cout << "It's a wonderful day for a picnic!" << std::endl;
    }
    else if (weather == "rainy")
    {
        std::cout << "Perfect weather to read a book indoors!" << std::endl;
    }
    else if (weather == "cloudy")
    {
        std::cout << "Maybe visit a museum?" << std::endl;
    }
    else if (weather == "snowy")
    {
        std::cout << "How about building a snowman?" << std::endl;
    }
    else if (weather == "windy")
    {
        std::cout << "Fly a kite if you have one!" << std::endl;
    }
    else
    {
        std::cout << "Please enter a valid weather condition (sunny, rainy, cloudy, snowy, windy)." << std::endl;
        return 1;
    }

    std::cout << "Footwear recommendation: ";
    switch (weather[0])
    {
    case 's':
        if (weather == "sunny")
        {
            std::cout << "Wear your favorite sneakers!" << std::endl;
        }
        else if (weather == "snowy")
        {
            std::cout << "Snow boots will keep your feet warm!" << std::endl;
        }
        break;
    case 'r': // rainy
        std::cout << "Rain boots are a great idea!" << std::endl;
        break;
    case 'c': // cloudy
        std::cout << "Any shoes will do today." << std::endl;
        break;
    case 'w': // windy
        std::cout << "Wear something sturdy!" << std::endl;
        break;
    default:
        std::cout << "Unknown footwear recommendation." << std::endl;
    }

    return 0;
}
