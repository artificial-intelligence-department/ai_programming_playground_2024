#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float a=100, b=0.0001;
    double a_d=100, b_d=0.0001;

    float result1, result2, finalresult;
    double result1d, result2d, finalresultd;
    //float
    result1 = (pow(a+b , 4)) - (pow(a,4)+4*pow(a,3)*b+6*pow(a,2)*pow(b,2));
    result2 = 4*a*pow(b,3) + pow(b,4);
    finalresult = result1/result2;
    //double
    result1d = (pow(a_d+b_d , 4)) - (pow(a_d,4)+4*pow(a_d,3)*b_d+6*pow(a_d,2)*pow(b_d,2));
    result2d = 4*a_d*pow(b_d,3) + pow(b_d,4);
    finalresultd = result1d/result2d;

    cout<<finalresult<<endl;
    cout<<finalresultd;

    return 0;
}