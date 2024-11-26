#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double sum = 0;
    for(int n = 0; n <= 9; n++) sum += exp(-sqrt(n));
    cout << sum << endl;
}