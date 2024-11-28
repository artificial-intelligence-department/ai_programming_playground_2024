#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double S, R, a = 0.7 , b = 0.05, x = 0.5;
    R = (pow(x, 3)*(x + 1)) / pow(b, 2) - pow(sin(x * (x + a)), 2);
    S = sqrt(x * b / a) + pow(cos(pow((x + b), 3)), 2);
    cout << "S = " << S << endl << "R = " << R;
    return 0;
}