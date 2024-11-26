#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float r1, r2;
    cout << "Enter resistance of the first resistor: ";
    cin >> r1;
    cout << "Enter resistance of the second resistor: ";
    cin >> r2;
    float R;
    R = (r1 * r2)/(r1 + r2); 
    cout << "Resistance of electric circuit: " << R;


    return 0;
}