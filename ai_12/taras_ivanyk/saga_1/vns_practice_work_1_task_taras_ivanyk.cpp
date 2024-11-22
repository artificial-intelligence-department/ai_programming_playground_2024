// 8 variant
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const double x = 1.82;
    const double y = 18.5;
    const double z = -3.4;
    double gamma, fi;
    gamma = abs(pow(x,y/x) - pow(y/x, 1/3));
    fi = (x - y) * (y - z/(y - x)) / (1 + pow( (y-x), 2));
    cout << "Gamma = " << gamma << ", Fi = " << fi;

    return 0;
}