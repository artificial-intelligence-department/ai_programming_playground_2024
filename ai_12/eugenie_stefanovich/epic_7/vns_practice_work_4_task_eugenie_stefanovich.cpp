#include <iostream>

using namespace std;

int main()
{
   for(double x = -2 , hx = 0.5; x <= 2 ; x += hx )
        cout << "y = " << (-2.4 * x) + 5*x - 3 << "     x = " << x << endl;
   
    return 0;
}