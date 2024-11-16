#include <iostream>
#include <string>


int main()
{
    enum Weather {sunny, rainy, cloudy, snowy, windy};
    int userOptionEnum;
    std::string userOption;
    do {
        std::cout << "Enter weather today (sunny, rainy, cloudy, snowy, windy): ";
        std::cin >> userOption;
    }
    while (!(userOption == "sunny" || userOption == "rainy" || userOption == "clody" || userOption == "snowy" || userOption == "windy"));
    

    //if else:
    if (userOption == "snowy" || userOption == "rainy")
        std::cout << "You schould wear a coat today :)" << std::endl;
    else
        std::cout << "You schould not wear a coat today :)" << std::endl;

    //if, else if:
    if(userOption == "sunny")
    {
        std::cout << "That's a great day for picnic!" << std::endl;
        userOptionEnum = 0;
    }
    else if(userOption == "rainy")
    {    
        std::cout << "Good day for reading inside :3" << std::endl;
        userOptionEnum = 1;
    }
    else if(userOption == "cloudy")
    {    
        std::cout << "Maybe you should visit a museum?)" << std::endl;
        userOptionEnum = 2;
    }
    else if(userOption == "snowy")
    {    
        std::cout << "What about making a snowman!!!?" << std::endl;
        userOptionEnum = 3;
    }
    else
    {    
        std::cout << "If you have a kite, fly it :3" << std::endl;
        userOptionEnum = 4;
    }
    //switch case:
    switch (userOptionEnum)
    {
        case 0:
            std::cout << "Put on your favorite trainers ))";
            break;
        case 1:
            std::cout << "Rain boots is a great idea!";
            break;
        case 2:
            std::cout << "Any shoes is suitable :)";
            break;
        case 3:
            std::cout << "Winter boots will make your feet warm :3";
            break;
        case 4:
            std::cout << "Put on your feet something durable!";
            break;


    }


    return 0;
}