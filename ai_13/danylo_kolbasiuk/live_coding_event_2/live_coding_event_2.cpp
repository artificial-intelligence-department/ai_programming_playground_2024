#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>

int distanceinMeteres(int distance, std::string type)
{
    if(type=="mile")
    {
        distance*=1609.344;
    }
    if(type=="mile_US")
    {
        distance*=1609.347;
    }
    if(type=="meter")
    {
        return distance;
    }
    return distance;
}

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
        std::ifstream ifile("mi.txt");
        ifile >> price;
        ifile.close();
    }
    else if(type_of_distance=="mile_US")
    {
        std::ifstream ifile("mi_US.txt");
        ifile >> price;
        ifile.close();
    }
    else if(type_of_distance=="meter")
    {
        std::ifstream ifile("m.txt");
        ifile >> price;
        ifile.close();
    }
    else
    {
        std::cout << "No such type of distance." << std::endl;
        return 0;
    }
    std::string file_name="IDs.txt";
    int tempo=distance;
    if(palindrome(tempo))
    {
        bonus+=200;
    }
    std::ofstream ofile(file_name);
    for(int i=0; i<len; i++)
    {
        ofile << array[i];
    }
    ofile << " " << bonus << std::endl;
    int discount=0;
    int temp=distance;
    ofile.close();
    std::cout << "Distance of current delivery: " << distanceinMeteres(temp, type_of_distance) << std::endl;
    std::cout << "Your discount: " << discount << "$" << std::endl;
    std::cout << "Total price: " << distance*price << "$" << std::endl;
}
