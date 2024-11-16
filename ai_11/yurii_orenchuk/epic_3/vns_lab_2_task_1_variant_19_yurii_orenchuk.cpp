#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double recursiveSum(int n, double accuracy) {
    double calc = n / pow((n - 1), 2);

    if (calc < accuracy)
        return 0;

    return calc + recursiveSum(n + 1, accuracy);
}

int main() {
    double accuracy = 0.0001;
    decltype(accuracy) sum = recursiveSum(2, accuracy);

    cout << typeid(sum).name() << " " << setprecision(10) << sum << endl;
    return 0;
}