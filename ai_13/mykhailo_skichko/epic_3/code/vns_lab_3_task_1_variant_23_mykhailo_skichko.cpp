#include <iostream>
#include <cmath>
#include <iomanip>

long long factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	long long fact = 1;
	for (int i = 2; i <= n; ++i)
		fact *= i;
	return fact;
}

double taylorSeries(double x, int n)
{
	double sum = 0.0;
	for (int i = 1; i <= n; ++i)
	{
		double term = pow(-1, i) * pow(2 * x, 2 * i) / factorial(2 * i);
		sum += term;
	}
	return sum;
}

double taylorSeriesPrecision(double x, double epsilon)
{
	double sum = 0.0;
	double term;
	int i = 1;
	do
	{
		term = pow(-1, i) * pow(2 * x, 2 * i) / factorial(2 * i);
		sum += term;
		++i;
	} while (fabs(term) > epsilon);
	return sum;
}

int main()
{
	double a = 0.1, b = 1.0;
	int k = 10;
	double step = (b - a) / k;

	int n = 15;
	double epsilon = 0.0001;

	std::cout << std::setw(10) << "x" << std::setw(20) << "Exact y"
			  << std::setw(20) << "Taylor (n=15)" << std::setw(20) << "Taylor (epsilon)" << std::endl;
	std::cout << std::string(70, '-') << std::endl;

	for (double x = a; x <= b; x += step)
	{
		double exactY = 2 * (pow(cos(x), 2) - 1);
		double taylorN = taylorSeries(x, n);
		double taylorEps = taylorSeriesPrecision(x, epsilon);

		std::cout << std::setw(10) << x << std::setw(20) << exactY
				  << std::setw(20) << taylorN << std::setw(20) << taylorEps << std::endl;
	}

	return 0;
}
