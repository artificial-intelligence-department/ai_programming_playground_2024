#include <stdio.h>
#include <iostream>
#include <string.h>


int findNumber(char *s){
    int number = 0;
    gets(s);
    char *temp;
    temp = strtok(s, " ");
    if(temp[0] == 'a')
        ++number;
    while(temp!=nullptr){
        temp = strtok(nullptr, " ");
        if(temp != nullptr && temp[0] == 'a')
            ++number;
    }
    return number;
}






int main(){


char sentence[255];
std::cout << "Enter your sentence: ";
int result = findNumber(sentence);

std::cout << "Your sentence contains " << result << " words that start with 'a'";


    return 0;
}