#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double ad = 100;
    double bd = 0.001;
    cout << "a = " << ad << " b = " << bd << "\n";

    double dSumFour = pow((ad + bd), 4);
    double adFour = pow((ad), 4);
    double adThree = pow((ad), 3);
    double dBrackets = adFour + (4 * adThree * bd);
    double dNumerator = dSumFour - dBrackets;

    double adTwo = pow((ad), 2);
    double bdTwo = pow((bd), 2);
    double bdThree = pow((bd), 3);
    double bdFour = pow((bd), 4);
    double dDenominator = (6 * adTwo * bdTwo) + (4 * ad * bdThree) + bdFour;

    double resultd = dNumerator / dDenominator;
    cout << "Результат через double: " << resultd << "\n";

    float af = 100;
    float bf = 0.001;
    cout << "a = " << af << " b = " << bf << "\n";

    float fSumFour = pow((af + bf), 4);
    float afFour = pow((af), 4);
    float afThree = pow((af), 3);
    float fBrackets = afFour + (4 * afThree * bf);
    float fNumerator = fSumFour - fBrackets;

    float afTwo = pow((af), 2);
    float bfTwo = pow((bf), 2);
    float bfThree = pow((bf), 3);
    float bfFour = pow((bf), 4);
    float fDenominator = (6 * afTwo * bfTwo) + (4 * af * bfThree) + bfFour;

    float resultf = fNumerator / fDenominator;
    cout << "Результат через float: " << resultf << "\n";

    return 0;
}