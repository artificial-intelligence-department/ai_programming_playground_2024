#include <stdio.h>
#include <iostream>

void deleteUnwantedWhitespaces(char*& str){
    char* newStr = new char[255];
    int i = 1;
    int counter = 0;
    while(str[i - 1] != '\0'){
        if(str[i] != ' ' || str[i - 1] != ' ') newStr[counter++] = str[i - 1];
        i++;
    }
    delete[] str;
    newStr[counter] = '\0';
    str = newStr;
}

char* getFirstWord(char* str){
    int i = 0; 
    char* word = new char[255];
    int size = sizeof(str) / sizeof(char);
    while(!(str[i] > 64  && str[i] < 91) && !(str[i] > 96  && str[i] < 123)) i++;
    int counter = 0;
    while(str[i] != ' ' && str[i] != '\0'){
        word[counter++] = str[i++];
    }
    word[counter] = '\0';
    return word;
}

char* getAllOccurences(char* word, char* str){
    char* allOccurence = new char[255];
    int counter = 0;
    for(int j = 0; str[j] != '\0'; j++){
        bool isWord = true;
        int i = 0;
        if(!(j == 0 || str[j - 1] == ' ')) isWord = false;
        while(word[i] != '\0' && isWord){
            if(str[j+i] != word[i++]) isWord = false;
        }
        if(isWord && (str[j + i] == ' ' || str[j + i] == '\0')){
            for(int i = 0; word[i] != '\0'; i++) allOccurence[counter++] = word[i];
            allOccurence[counter++] = ' ';
        }
    }
    allOccurence[counter] = '\0';
    return allOccurence;
}

int main(){         //Надрукувати всі слова, які співпадають з її першим словом
    char* str = new char[255]; 

    gets(str);
    deleteUnwantedWhitespaces(str);
    char* word = getFirstWord(str);
    char* occurences = getAllOccurences(word, str);
    std::cout <<"All occurences of word " << word << " : "<< occurences;
    delete[] word;
    delete[] occurences;
    delete[] str;
    return 0;
}