#include <iostream>



int main(){

std::string weather;

std::cout << "Tell me about your weather conditions.\nIs it sunny, rainy, cloudy, snowy or windy? ";
while(true){
    std::cin >> weather;
    if (weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy"){
        break;
    }
    else
        std::cout << "Something wrong here, try once more. ";
        continue;
}



if(weather == "rainy" || weather == "snowy")
    std::cout << "You should take your jacket" << std::endl;
else
    std::cout << "You don't need a jacket" << std::endl;

int w;
if(weather == "sunny"){
    std::cout << "A great day for a picnic!" << std::endl;
    w = 1;
}
else if(weather == "rainy"){
    std::cout << "Perfect weather to read a book indoors!" << std::endl;
    w = 2;
}
else if(weather == "cloudy"){
    std::cout << "Let's go to the museum" << std::endl;
    w = 3;
}
else if(weather == "snowy"){
    std::cout << "How about making a snowman?" << std::endl;
    w = 4;
}
else if(weather == "windy"){
    std::cout << "Fly a kite if you have one!" << std::endl;
    w = 5;
}

switch (w){
    case 1: 
        std::cout << "Wear your favorite shoes!" << std::endl;
        break;
    case 2:
        std::cout << "Rain boots are a good idea!" << std::endl;
        break;
    case 3:
        std::cout << "Today, any shoe is suitable." << std::endl;
        break;
    case 4:
        std::cout << "Snow boots will keep your feet warm!" << std::endl;
        break;
    case 5:
        std::cout << "Wear something sturdy!" << std::endl;
        break;
};








    return 0;
}
    