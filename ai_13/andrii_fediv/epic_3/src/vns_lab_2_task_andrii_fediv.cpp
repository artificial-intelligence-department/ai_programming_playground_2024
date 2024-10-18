#include <iostream>
#include <cmath>

double calculateSum(double e)
{
    int n = 1;
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//
    /*AAAAAAAAAAA*/                 double sum_series = 1.5;                      /*AAAAAAAAAAA*/
    /*AAAAAAAAAAA*/                         double An;                            /*AAAAAAAAAAA*/
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//
    double An1 = 0.5;
    while (true)
    {
        // recurent for =a * (n+1)^2 / 2^(n+1) 
        double q = pow(2, ((2 * n) + 1)) / pow((n + 1), 2);
        An = An1 / q ;

        if (An < e)
        {
            break;
        }

        sum_series += An;
        n++;
        An1 = An;
    }

    return sum_series;
}

int main()
{
    double e = 0.0001;
    double sum = calculateSum(e);

    std::cout << "sum of set with accuracy e = " << e << ": " << sum << std::endl;

    return 0;
}
