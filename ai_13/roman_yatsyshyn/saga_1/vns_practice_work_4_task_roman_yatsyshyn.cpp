#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double sum = 0;
    double minusone = -1.0;
    int n;
    cout << "Number of element: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        sum += pow(minusone, i)*(1.0/(2.0*i + 1.0));
    }
    cout << "S = " << sum << endl;
    cout << "S - π/4 = " << (sum - M_PI_4);
}