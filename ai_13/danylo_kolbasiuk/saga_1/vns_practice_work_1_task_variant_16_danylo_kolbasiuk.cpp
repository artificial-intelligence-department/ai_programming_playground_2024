#include <iostream> 
#include <cmath>

int main()
{
    double x=0.25;
    double y=0.79;
    double z=0.81;
    double temp1=1+pow(sin(x+1),2);
    double temp2=1+pow(x,2)*pow(y,3);
    double temp3=2+fabs(x-(2*pow(x,3))/temp2);
    double P=(temp1/temp3)+pow(x,4);
    double Q=pow(cos(atan(1/z)),2);
    std::cout << P << " " << Q;
}