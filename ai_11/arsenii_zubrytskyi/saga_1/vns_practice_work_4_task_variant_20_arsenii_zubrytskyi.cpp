#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

    double x = -4.0, y;
    double step = 0.5;

    cout << left;
    cout << "<<Table Value>>" << endl;
    cout << setw(4) << "x" << " | " << setw(8) << "y = |x - 2| + |x + 1|" << endl;

    for(; x <= 4; x += step){
        y = abs(x - 2) + abs(x + 1);
        cout << setw(4) << x << " | " << y << endl;
    }
    
    return 0;
}