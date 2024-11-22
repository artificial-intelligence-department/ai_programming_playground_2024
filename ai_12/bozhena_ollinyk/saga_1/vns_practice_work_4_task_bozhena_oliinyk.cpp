#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double y, x[1][18];
    int n = 0;
    for (double i = -4; i <= 4; i += 0.5)
    {
        x[1][n] = i;
        n++;
    }

    int j = 0;
    while(j < n){
        y = fabs(x[1][j] - 2) + fabs(x[1][j] + 1);
        cout << "x = " << x[j] << "   " << '\t' << "y = " << y << endl;
        j++;
    }

}