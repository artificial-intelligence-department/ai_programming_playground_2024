#include <iostream>
#include <cmath>
#include <vector>

// Функція, що перевіряє, чи належить точка (x, y) кругу з радіусом R
bool isInsideCircle(double x, double y, double R) 
{
    return (x * x + y * y) <= (R * R);
}

// Функція, що визначає кількість точок, які належать кругу
int belong(double R, double points[][2], int numPoints) 
{
    int count = 0;
    for (int i = 0; i < numPoints; ++i)
     {
        double x = points[i][0];
        double y = points[i][1];
        if (isInsideCircle(x, y, R))
        {
            ++count;
        }
    }
    return count;
}
int main()
 {
    double R = 5.0;

    // Масив з 3 точками
    double points1[3][2] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    std::cout << "Точок всередині кола (3 точки): " << belong(R, points1, 3) << std::endl;

    // Масив з 9 точками
    double points2[9][2] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}, {9.0, 10.0}, {11.0, 12.0}, {13.0, 14.0}, {15.0, 16.0}, {17.0, 18.0}};
    std::cout << "Точок всередині кола (9 точок): " << belong(R, points2, 9) << std::endl;

    // Масив з 11 точками
    double points3[11][2] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}, {9.0, 10.0}, {11.0, 12.0}, {13.0, 14.0}, {15.0, 16.0}, {17.0, 18.0}, {19.0, 20.0}, {21.0, 22.0}};
    std::cout << "Точок всередині кола (11 точок): " << belong(R, points3, 11) << std::endl;

    return 0;
}