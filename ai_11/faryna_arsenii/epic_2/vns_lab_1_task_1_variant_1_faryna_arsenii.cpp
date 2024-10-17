#include <iostream>
#include <cmath>
#include <iomanip> //for setprecion

using namespace std;

int main (){

    //for double
    double a = 1000, b = 0.0001;
    double numenator1, denominator1, res1;

    numenator1 = pow((a + b), 3) - pow(a, 3);
    denominator1 = 3*a*b + pow(b, 3) + 3*pow(a, 2)*b;

    cout << setprecision(10) << "numerator1 = " << numenator1 << "\ndenominator1 = " << denominator1;
    res1 = numenator1 / denominator1;
    cout << setprecision(10) <<"\nresult for double: " << res1 << endl;
    //for double result is true

    //for float
    float a1 = 1000, b1 = 0.0001;
    float numenator2, denominator2, res2;

    numenator2 = pow((a1 + b1), 3) - pow(a1, 3);
    denominator2 = 3*a1*b1 + pow(b1, 3) + 3*pow(a1, 2)*b1;

    res2 = numenator2 / denominator2;
    cout << "\nnumenator2 = " << numenator2 << "\ndenominator2 = " << denominator2 << "\nresult for float = " << res2 << endl;
    return 0;
}
