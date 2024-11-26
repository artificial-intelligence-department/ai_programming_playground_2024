#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    FILE* f1 = fopen("input.txt", "r");
    FILE* f2 = fopen("output.txt", "w");
    
    char s[256], max_s[256];
    if(f1 == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для читання!";
        return 1;
    }
     if(f2 == nullptr)
    {
        cerr<<"Не вдалося відкрити файл для запису!";
        return 1;
    }
    
    

    int max_num_of_vowels = 0, index = 0, max_index, num_of_vowels = 0;
    while (fgets(s, sizeof(s), f1) != NULL)
    {
        num_of_vowels = 0;
        index++;

        for (int i = 0; i < sizeof(s); i++)
        {
            if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u') || (s[i] == 'y'))  num_of_vowels++;   
        }
        
        if (num_of_vowels > max_num_of_vowels)
        {
            max_num_of_vowels = num_of_vowels;
            max_index = index;
        }
    }
    fclose(f1);

    index = 0;
    f1 = fopen("input.txt", "r");
    while (fgets(s, sizeof(s), f1) != NULL)
    {
       index++;
       if (index != max_index)
       {
            fputs(s, f2);
       } 
    }
    cout<<"Номер рядка з найбільшою кількістю голосних: "<<max_index<<endl;
    
    fclose(f1);
    fclose(f2);
    return 0;
}