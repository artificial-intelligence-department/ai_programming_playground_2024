#include <cmath>
#include <iostream>

#define LEN(xa,ya,xb,yb) sqrt(((xb)-(xa))*((xb)-(xa))+((yb)-(ya))*((yb)-(ya)))

int main()
{
    double x[3], y[3];
    for(int i = 0; i < 3; i++)
    {
        std::cout << "Enter x" << i+1 << ", y" << i+1 << ": ";
        std::cin >> x[i] >> y[i];
    }
    double a = LEN(x[0],y[0],x[1],y[1]);
    double b = LEN(x[0],y[0],x[2],y[2]);
    double c = LEN(x[1],y[1],x[2],y[2]);
    double p = (a+b+c)/2;
    double area = sqrt(p*(p-a)*(p-b)*(p-c));
    std::cout << "Area = " << area << std::endl;
}