#include <iostream>
#include <cmath> 
using namespace std;

int main() 
{
    int n; 
    cout << "Enter number of student: ";
    cin >> n;

    int a = n;

    if (a < 2 || a > 10)
    {
        cout << "His number must be in arange from 2 to 10." << endl;
        return 1;
    }

    double x_start = 1.0, x_end = 8.0, x_step = 0.5;
    double a_start = 2.0, a_end = 10.0, a_step = 1.0;

    for (double x = x_start; x <= x_end; x += x_step) 
    {
        for (double num = a_start; num <= a_end; num += a_step) 
        {
            double y;
            if (x < num) 
            {
                y = pow(num, 2) + x; 
            }
            else if (x == num) 
            {
                y = pow(num, 2); 
            }
            else 
{
                y = pow(num, 2) - x; 
            }

            cout << "x = " << x << ", a = " << num << " -> y = " << y << endl;
        }
    }





    return 0;
}


















