#include <iostream>
#include <cmath>

using namespace std;

int main (){
 double a = 1.1;
 double b = 0.004;
 double x = 0.2;
 double y,z;

y = pow (sin(pow (a,2)),3) - pow (x/b, 1/3);
cout << y << endl;
z = pow (x,2)/a + pow (cos(pow (x+b,3)), 2);
cout << z << endl;

return 0;
}