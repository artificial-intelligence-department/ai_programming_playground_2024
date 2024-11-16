#include <iostream>
#include <array>

int howMany(const std::array<int, 8> &array){
    int i = 0;
    for(auto el:array){
        if(el % 2 == 1)
            ++i;
    }
    return i;
}


int howMany(std::string words){
    int c = 0;
    for(auto el: words){
        if(el == ' ')
            ++c;
    }
    return c+1;
}




int main(){

std::array<int, 8> array = {1, 2, 3, 4, 5, 6, 7, 8};
std::string words = "I am doing third epic";

std::cout << "Number of odd numbers: " << howMany(array) << std::endl;
std::cout << "Number of words: " << howMany(words);


    return 0;
}