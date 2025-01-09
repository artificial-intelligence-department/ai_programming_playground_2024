#include <iostream>

int main()
{
    double sdown, sup, speed;
    std::cin >> sdown >> sup >> speed;
    double tdown=sdown/(2.0*speed);
    double tup=(2.0*sup)/speed;
    if(tdown < tup)
    {
        std::cout << "Down";
    }
    else if(tdown == tup)
    {
        std::cout << "Never mind";
    }
    else
    {
        std::cout << "Up";    
    }
}