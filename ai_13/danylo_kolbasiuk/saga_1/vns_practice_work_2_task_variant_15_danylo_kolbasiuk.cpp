#include <iostream>
#include <cmath>

int main()
{
    double x=1;
    double a=-0.5;
    double xstep=0.5;
    double astep=0.2;
    while(x<=4)
    {
        double temp1=sqrt(x-1.5); 
        double temp2=pow(x,a);
        double temp3=temp1+temp2;
        double temp4=pow(x-2,1/3);
        double z=temp3/temp4;
        std::cout << x << " " << a << " " << z << std::endl; // при х=1 функція не має значення
        x+=xstep;
        a+=astep;
    }
}