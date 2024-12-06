#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //Calculate cube volume
    double edgeLength;

    cout<<"Enter the length of the edge (cm) and press <Enter>: ";
    cin>>edgeLength;

    cout<<"Cube volume: "<< pow(edgeLength, 3)<<" cm^3\n"<<endl;

    //Calculate R
    double resistor1, resistor2;

    cout<<"Enter the resistance of the first resistor (Ohms) and press <Enter>: ";
    cin>>resistor1;

    cout<<"Enter the resistance of the second resistor (Ohms) and press <Enter>: ";
    cin>>resistor2;

    cout<<"Total resistance of the electrical circuit: "<< 1.0 / ((1.0 / resistor1) + (1.0 / resistor2))<<" Ohms.\n"<<endl;

    return 0;
}