#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float fa = 1000, fb = 0.0001, fc, fd, f_result;
    double da = 1000, db = 0.0001, dc, dd, d_result;


    // float
    fc = pow((fa+fb),3);
    fd = 3*fa*pow(fb,2) + pow(fb,3) + 3*pow(fa,2)*fb;
    f_result = (fc - pow(fa,3))/fd ;

    cout << "Result of calculations in float : " << f_result;
    
    // double
    dc = pow((da+db),3);
    dd = 3*da*pow(db,2) + pow(db,3) + 3*pow(da,2)*db;
    d_result = (dc - pow(da,3))/dd ;

    cout << "\nResult of calculations in double : " << d_result;
}
