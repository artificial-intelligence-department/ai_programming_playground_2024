#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if (n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
int main() {
    double sum = 0.0;
    double temp;
    int i = 0;
    do {
        temp = (pow(3, i) * factorial(i)) / factorial(3 * i);
        sum += temp;
        ++i;
    } while (abs(temp) > 0.0001);
    cout << sum;
    return 0;
}
