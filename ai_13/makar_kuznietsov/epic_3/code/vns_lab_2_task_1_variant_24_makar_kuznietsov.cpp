#include <cmath>
#include <iostream>

float recSeries(int n);

int main()
{
    int n = 9;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(M_E, -1 * sqrt(n));
    }
    // double result = recSeries(n);
    // std::cout << result;
    std::cout << "sum of first 9 elements:" << sum;
}

// double recSeries(int n)
// {
//     if (n > 0)
//     {
//         // std::cout << n << '\n';
//         // std::cout << pow(M_E, -1 * sqrt(n)) << '\n';
//         return pow(M_E, -1 * sqrt(n)) + recSeries(n - 1);
//     }
//     else
//     {
//         return 0;
//     }
// }
