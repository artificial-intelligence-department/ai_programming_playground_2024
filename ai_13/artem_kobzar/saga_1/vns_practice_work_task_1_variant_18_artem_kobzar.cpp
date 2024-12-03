#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 10.2, b = 9.3, x = 2.4, c = 0.5;
    double K = log(a + pow(x, 3)) + pow(sin(x / b), 2);
    double M = exp(-c * x) * (x + cbrt(x + a)) / (x - sqrt(abs(x - b)));
    cout << "K equals: " <<K<<endl;
    cout << "M equals: "<<M<<endl;
    return 0;
}
