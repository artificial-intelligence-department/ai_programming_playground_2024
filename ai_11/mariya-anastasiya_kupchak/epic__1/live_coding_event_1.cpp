#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

double function_1()
{
    float a, b; 
    int c, d, e; 
    double f;

    cin >> a >> b >> c >> d >> e >> f;

    double mas[6] = {static_cast<double> (a), static_cast<double> (b), static_cast<double> (c), static_cast<double> (d), static_cast<double> (e), f};
    
    sort(mas, mas+6);

    double t;

    if ((mas[5] + mas[4] + mas[3]) > ((mas[0] + mas[1] + mas[2]) * 2))
    {
        t = (mas[5] + mas[4] + mas[3]) * (mas[0] + mas[1] + mas[2]);
    }

    if ((mas[5] + mas[4] + mas[3]) > ((mas[0] + mas[1] + mas[2]) * 3))
    {
        t = (mas[5] + mas[4] + mas[3]) / (mas[0] + mas[1] + mas[2]);
    }

    if ((mas[5] + mas[4] + mas[3]) > ((mas[0] + mas[1] + mas[2]) * 4))
    {
        t = (mas[5] + mas[4] + mas[3]) + (mas[0] + mas[1] + mas[2]);
    }

    double x = t / 14;
    return x;
}

double function_2(double x)
{
    double array[5][5] = { x };
    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            array[row][col] = (array[row][col] + 14 + col - row) * (rand() % 100);
        }
    }

    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            cout << array[row][col] << " ";
        }

        cout << endl;
    }

    return array[][];
}

int main()
{
    double x = function_1();
    double &ref = x;
    // передати в головну функцію масив, но чогось не получилось, функція не хоче його повертати
    
    return 0;
}