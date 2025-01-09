#include <iostream>
#include <cmath> 
using namespace std;

int main() 
{

    double CubeLength;  
    double volume;     


    cout << "Enter lenght cube : ";

    cin >> CubeLength;

    volume = pow(CubeLength, 3);

    cout << "Cube volume: " << volume << " cm." << endl;



    return 0;
}









