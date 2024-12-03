#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

int main()
{
    for (double x = 1; x <= 4; x += 0.5) {

        double z = fabs(x) + pow(x, 3);
        
        double numerator = pow(sin(2 + x), 2);
        double denominator = 2 + x;
        double y = z * (numerator / denominator);

        cout << "x = " << x << " -> Y = " << y << ", Z = " << z << endl;
    }

    return 0;
}
