// 8 variant an = (2n - 1)/2**n
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout << "Please input n: ";
    int n;
    double sum;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        sum += (2*i - 1)/pow(2,i);
    }

    printf("%.4lf", sum);

    return 0;
}