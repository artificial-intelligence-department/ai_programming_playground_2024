#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double sides[] = {3, 21, 20};
    double p = (sides[0] + sides[1] + sides[2]) / 2, area;

    for ( int i = 0, u = 1; i < 3; i++){
        area = (2 / sides[i]) * (sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2])));
        cout << "h " << u++ << " = " << area << endl;
    }
    
    return 0;
}