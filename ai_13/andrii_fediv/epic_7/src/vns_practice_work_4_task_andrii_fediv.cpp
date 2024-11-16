#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    ostringstream line1, line2;
    line1 << " x |";
    line2 << " y |";
    string line25 = "----";

    for (double x = -2; x <= 2; x += 0.5)
    {
        line25 += "--------";
        double y = -2.4 * x + 5 * x - 3;
        line1 << fixed << setprecision((x - int(x) ? 1 : 0)) << " " << setw(5) << x << " |";
        line2 << fixed << setprecision((y - int(y) ? 1 : 0)) << " " << setw(5) << y << " |";
    }
    cout << line1.str() << endl
         << line25 << endl
         << line2.str();
    return 0;
}