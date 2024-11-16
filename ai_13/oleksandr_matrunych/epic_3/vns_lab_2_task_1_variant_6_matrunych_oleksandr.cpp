#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double epsilon = 0.0001;
    double sum = 0.0;
    int n = 1;
    double a;
    while (true) {
        a = 1.0 / pow(2, n) + 1.0 / pow(3, n);
        sum += a;
        n++;
        if (a < epsilon) {
            break;
        }
    }
    cout << "Sum "<< "= " << sum << endl;
    return 0;
}