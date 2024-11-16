#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 1000.0d;
    double b = 0.0001d;
    double numer = pow((a - b), 3) - pow(a, 3);
    double denomin = pow(b, 3) - 3*a*b*b - 3*b*a*a;

    cout << "The result: " << numer/denomin;


    return 0;
}