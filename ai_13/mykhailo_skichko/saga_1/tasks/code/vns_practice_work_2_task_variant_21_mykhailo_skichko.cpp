#include <iostream>
#include <cmath>

double calculateHeight_a(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	double height_a = 2 / a * sqrt(p * (p - a) * (p - b) * (p - c));
	return height_a;
}

int main()
{
	double a, b, c;
	double maxHeight = 0;
	int maxIndex = 0;

	std::cout << "Enter 3 sides of 5 triangles (a b c):\n";
	for (int i = 1; i <= 5; ++i)
	{
		std::cout << "triangle " << i << ": ";
		std::cin >> a >> b >> c;

		double h_a = calculateHeight_a(a, b, c);
		if (h_a > maxHeight)
		{
			maxHeight = h_a;
			maxIndex = i;
		}
	}

	std::cout << "\nThe largest height h_a = " << maxHeight
			  << " is in \"triangle " << maxIndex << "\"\n";

	return 0;
}
