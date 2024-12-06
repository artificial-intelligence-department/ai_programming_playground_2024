#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x_start = -4.0; // Мінімальний x
    double x_end = 4.0;    // Максимальний x
    double step = 0.5;     // крок приросту аргументу 0,5.

    cout << "Table of values for y = |x - 2| + |x + 1|" << endl;
    cout << setw(13) << "x" << setw(13) << "y" << endl; 
    cout << "|-----------------------------------|" << endl;

    for (double x = x_start; x <= x_end; x += step) {
        double y = abs(x - 2) + abs(x + 1); // Обчислення y відносно x  
        cout << setw(13) << x << setw(13) << y << endl;
        cout << "|-----------------------------------|" << endl;
    }

    return 0;
}
