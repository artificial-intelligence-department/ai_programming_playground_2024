#include <iostream>
#include <cmath> // підключив бібліотеку для pow() та tan()
using namespace std;

int main(){

    double x = 1.23; // ініціалізація x
    double y = 0.79; // ініціалізація y

    double a = y + x / (pow(y, 3) + abs(pow(x, 2)/(y + pow(x, 2.0/3.0)))); // формула для a
    double tg = tan( x / 2 ); // обрахунок тангенса 
    double b = 1 + pow(tg, 2); // формула для b

    cout << "Value of a = " << a <<  "\t\tValue of b = " << b << endl << endl; // вивід значень
    return 0;
}