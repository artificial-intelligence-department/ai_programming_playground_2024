#include <iostream>
#include <ostream>
int main()
{
    int weather;
    std::cout << "What is the weater like today?" << '\n'
              << "(1 = sunny" << '\n'
              << "2 = rainy" << '\n'
              << "3 = cloudy" << '\n'
              << "4 = snowy" << '\n'
              << "5 = windy)" << '\n';
    ;
    std::cin >> weather;
    if (weather == 4 || weather == 2)
    {
        std::cout << "Wear a coat." << '\n';
    }
    else
    {
        std::cout << "Dont wear a coat." << '\n';
    }

    if (weather == 1)
    {
        std::cout << "Great day for a picnic!" << '\n';
    }
    else if (weather == 2)
    {
        std::cout << "Great day to read a book inside!" << '\n';
    }
    else if (weather == 3)
    {
        std::cout << "What about visiting the museum?" << '\n';
    }
    else if (weather == 4)
    {
        std::cout << "What about making a snowman?" << '\n';
    }
    else if (weather == 5)
    {
        std::cout << "Fly the kite!" << '\n';
    }
    switch (weather)
    {
    case 1:
        std::cout << "Wear favourite sneakers!" << '\n';
        break;
    case 2:
        std::cout << "Rain boots are a good idea!" << '\n';
        break;
    case 3:
        std::cout << "Any shoes will go." << '\n';
        break;
    case 4:
        std::cout << "Snow boots will keep your feet warm!" << '\n';
        break;
    case 5:
        std::cout << "Wear something durable!" << '\n';
        break;
    }
}
