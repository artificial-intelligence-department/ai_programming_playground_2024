#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    const int max_lenth = 255;
    char s[max_lenth + 1];
    cout << "Введіть слова: ";
    gets(s);

    int lenth = 0;

    while (s[lenth] != '\0')
    {
       lenth++; 
    }
    
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < lenth; i++)
    {
        if (s[i] != ' ' || s[i] !=  '.' || s[i] != '\t')
        {
            if (!inWord)
            {
                inWord = true;
                count++;
            }else if(s[i] == ' ' || s[i] ==  '.' || s[i] == '\t'){
                inWord = false;
            }
            
        }
    }
    
    cout << "Кількість слів у рядку: " << count;

    return 0;
}