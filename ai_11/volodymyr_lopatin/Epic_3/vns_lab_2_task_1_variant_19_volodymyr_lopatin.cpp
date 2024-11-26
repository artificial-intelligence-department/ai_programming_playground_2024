#include <iostream>
using namespace std;

int main() {
    double n = 2.0;
    double a;
    double eps = 0.0001;
    double sum = 0.0;
    do {
        a = n/((n-1.0)*(n-1.0));
        sum += a;
        ++n;
    } while (a >= eps);
    cout << sum;
    return 0;
}