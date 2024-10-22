#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float result = 0;
    for (int n = 1; n < 8; n++)
    {
        int nToSquare = pow(n, 2);
        float sqrtPow = 0 - sqrt(n);
        float eToPow = pow(M_E, sqrtPow);

        result += (nToSquare * eToPow);
    }

    cout << "Result is: " << result; 

    return 0;
}