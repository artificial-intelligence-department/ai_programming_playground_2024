#include <iostream>
#include <cstring>

#define sLength 100

char** splitWords(const char* str, const char* delim, int& count) {
    char* strCopy = new char[strlen(str) + 1];
    strcpy(strCopy, str);

    count = 0;
    char* token = strtok(strCopy, delim);
    while (token != nullptr) {
        count++;
        token = strtok(nullptr, delim);
    }

    char** words = new char*[count];
    strcpy(strCopy, str);  
    token = strtok(strCopy, delim);
    int index = 0;
    while (token != nullptr) {
        words[index] = new char[strlen(token) + 1];
        strcpy(words[index], token);
        token = strtok(nullptr, delim);
        index++;
    }

    delete[] strCopy; 
    return words;
}

bool checkHas(const char* str, const char* charsSeq)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        for (size_t j = 0; j < strlen(charsSeq); j++)
        {
            if(str[i] == charsSeq[j]) return true;
        }
    }
    return false;
}


void printHasNoVowel(const char* str, const char* delim)
{
    int wordCount = 0; 
    const char vowels[] = "AEIOUaeiou";
    char** words = splitWords(str,delim,wordCount);
    for (size_t i = 0; i < wordCount; i++)
    {
        if(!checkHas(words[i],vowels))
        {
            std::cout << words[i] << " "; 
        } 
        delete[] words[i];
    }
    delete[] words;
}



int main(void)
{
    char cStr[sLength];
    std::cout << "Enter String: ";
    fgets(cStr, sLength, stdin);  

    cStr[strcspn(cStr, "\n")] = '\0';

    const char delim[] = " \t, .!?";

    printHasNoVowel(cStr,delim);


    return 0;
}
