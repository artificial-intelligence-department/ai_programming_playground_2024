#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double x = 1.82;    // 3. дійсна з подвійною точністю, для задання змінної
    double y = 18.5;
    double z = -3.4;
    double gamma, fi;       // 2. дійсна змінна, для результату
    gamma = abs(pow(x,y/x) - cbrt(y/x));    // 15. математичні функції для обрахування результату
    fi = ((x-y) * ((y-z)/(y-x)))/(1 + pow(y -x, 2));
    cout << "Gamma: " << gamma << endl;
    cout << "Fi: " << fi << endl;

    return 0;
}