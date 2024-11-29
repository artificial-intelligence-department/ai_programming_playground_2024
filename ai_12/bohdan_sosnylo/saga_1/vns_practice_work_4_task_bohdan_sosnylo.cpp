#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double y, x;

    cout << "x\ty\n";

    for (x = -4; x <= 4; x += 0.5) {
        y = fabs(x); 
        cout << x << "\t" << y << endl;
    }

    return 0;
}