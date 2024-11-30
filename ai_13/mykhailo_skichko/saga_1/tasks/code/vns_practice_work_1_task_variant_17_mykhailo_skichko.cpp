#include <iostream>
#include <cmath>

int main()
{
	double a = 3.2;
	double b = 17.5;
	double x = -4.8;
	double Y = pow(b, 3) * pow(tan(x), 2) - a / pow(sin(x / a), 2);
	double Z = a * exp(-sqrt(3)) * cos((b * x) / a);
	std::cout << Y << " " << Z;
}
