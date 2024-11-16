#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n = 9;
    double sum = 0.0;

    for (int i = 1;i <= n;i++) {
        double term = exp(-sqrt(i));
        sum += term;
    }

     cout << "The sum of the first 9 terms is: " << sum << endl;

return 0;

}