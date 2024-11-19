#include <iostream>
#include <string>

int main(){

std::string word;
std::cin >> word;

int myav = 0;

for(int i = 0; i < word.size() - 1; ++ i){
    if(word[i] == word[i+1]){
        ++myav;
    }
}


std::cout << myav;

    return 0;
}