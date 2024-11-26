#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n = 15;
    double SUM = 0.0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << "if n = " << i << ", then in [ ln(n) ]^n will be 0.\nWe can't divide by zero.\n";
            continue;
        }
        double STEP1 = pow(i, log(i));
        double STEP2 = pow(log(i), i);
        double STEP3 = STEP1 / STEP2;
        SUM += STEP3;
        cout << "if n = " << i << ", the result will be: "  << setprecision(6) << STEP3 << " (setprecision(unfixed) is 6)\n";

    }
    cout << "\nMath problem:\n\n";
    cout << "n^[ ln(n) ]\n";
    cout << "-----------\n";
    cout << "[ ln(n) ]^n\n\n";
    cout << "Final result: " << fixed << setprecision(2) << SUM << " (setprecision(fixed) is 2)";
    return 0;
}