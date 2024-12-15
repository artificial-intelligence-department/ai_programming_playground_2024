#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

double distance(double x1, double y1, double x2, double y2)
{
	return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool belongToTriangle(double x, double y, const std::pair<double, double> &p1,
					  const std::pair<double, double> &p2, const std::pair<double, double> &p3)
{
	double A = area(p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
	double A1 = area(x, y, p2.first, p2.second, p3.first, p3.second);
	double A2 = area(p1.first, p1.second, x, y, p3.first, p3.second);
	double A3 = area(p1.first, p1.second, p2.first, p2.second, x, y);
	return (A == A1 + A2 + A3);
}

bool belongToPolygon(double x, double y, const std::vector<std::pair<double, double>> &vertices)
{
	int n = vertices.size();
	bool inside = false;

	for (int i = 0, j = n - 1; i < n; j = i++)
	{
		double xi = vertices[i].first, yi = vertices[i].second;
		double xj = vertices[j].first, yj = vertices[j].second;

		if (((yi > y) != (yj > y)) &&
			(x < (xj - xi) * (y - yi) / (yj - yi) + xi))
		{
			inside = !inside;
		}
	}

	return inside;
}

int main()
{
	std::cout << "Distance between points: " << distance(0, 0, 3, 4) << std::endl;

	std::pair<double, double> p1 = {0, 0};
	std::pair<double, double> p2 = {5, 0};
	std::pair<double, double> p3 = {0, 5};
	double px = 1, py = 1;

	if (belongToTriangle(px, py, p1, p2, p3))
	{
		std::cout << "Point belongs to the triangle" << std::endl;
	}
	else
	{
		std::cout << "Point does not belong to the triangle" << std::endl;
	}

	std::vector<std::pair<double, double>> polygon = {{0, 0}, {5, 0}, {5, 5}, {0, 5}};
	double px2 = 3, py2 = 3;

	if (belongToPolygon(px2, py2, polygon))
	{
		std::cout << "Point belongs to the polygon" << std::endl;
	}
	else
	{
		std::cout << "Point does not belong to the polygon" << std::endl;
	}

	return 0;
}
