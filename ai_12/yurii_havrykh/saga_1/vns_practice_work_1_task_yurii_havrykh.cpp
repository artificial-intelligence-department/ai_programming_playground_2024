#include<bits/stdc++.h>

using namespace std;

int main() {
    int m = 2, c = 1;
    float x = 1.2, b = 0.7;
    float fi = sqrt(m * tan(x) + abs(c * sin(x)));

    float psi = m * cos(b * x + sin(x)) + pow(c, 3);

    cout << "fi= " << fi << endl;
    cout << "psi= " << psi << endl;
}