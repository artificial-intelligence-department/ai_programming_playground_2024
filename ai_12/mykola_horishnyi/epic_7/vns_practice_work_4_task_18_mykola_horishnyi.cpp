#include <iostream>
using namespace std;

int main() 
{
    double price_for_kg;  
    double weight; 
    double price; 

    cout << "Enter prize for 1 kilo: ";
    cin >> price_for_kg;


    cout << "Weight |  Prize  " << endl;
    cout << "--------------------------" << endl;

    for (weight = 100; weight <= 1000; weight += 100)
    {
        price = (price_for_kg * weight) / 1000;

        cout << weight << "  |  " << price << endl;
    }

    return 0;
}








