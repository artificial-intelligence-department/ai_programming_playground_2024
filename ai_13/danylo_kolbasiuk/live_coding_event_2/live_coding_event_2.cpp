#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>

void sort(char arr[], int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                char temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void value_of_id(char identifier[25], int len, int array[25])
{
    int i=0;
    sort(identifier, len);
    for(int i=0; i<len; i++)
    {
        array[i]=static_cast<int>(identifier[i])*0.4;
    }
}

bool palindrome(int distance)
{
    int temp=distance;
    int uno=temp;
    int onu=0;
    while (temp>0)
    {
        onu=onu*10+temp%10;
        temp=temp/10;
    }
    return uno==onu;
}

int main()
{
    char identifier[25];
    std::string type_of_distance;
    int distance;
    double price;
    bool bonus_check;
    std::cout << "Enter your name: ";
    std::cin >> identifier;
    std::cout << "Enter the distance: ";
    std::cin >> distance;
    std::cout << "Enter the type of distance: ";
    std::cin >> type_of_distance;
    std::cout << "Do you want to use your bonus? 0/1 ";
    std::cin >> bonus_check;
    int len=strlen(identifier);
    int array[25];
    double bonus=0;
    value_of_id(identifier, len, array);
    if(type_of_distance=="mile")
    {
        distance*=1609.344;
    }
    else if(type_of_distance=="mile_US")
    {
        distance*=1609.347;
    }
    else if(type_of_distance=="meter")
    {
        distance*=1;
    }
    std::string file_name="IDs.txt";
    
}
