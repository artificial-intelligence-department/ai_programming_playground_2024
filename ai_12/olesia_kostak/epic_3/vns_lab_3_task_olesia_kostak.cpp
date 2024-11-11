#include <iostream>
#include <cmath>


long long factorial(int num);
int main()
{
    // a) for given n
    int n = 15;
    for (float x = 1; x <= 2.1; x += 0.1)
    {
        long double counter = 0;
        for (int i = 0; i <= n; i++)
            counter += (pow(x, i)/ factorial(i));
        std::cout << "e in the " << x << " power: " << counter << std::endl;
    }

    std::cout << std::endl << "_________________________________________________________" << std::endl;

    // b) for given epsilon
    float eps = 0.0001;
    for (float x = 1; x <= 2.1; x += 0.1)
    {
        double diff = pow(M_E, x);
        int i = 0;
        double counter = 0;
        while (diff > eps)
        {
            counter += pow(x, i)/ factorial(i);
            diff = fabs(pow(M_E, x) - counter);
            i++;
        }
        std::cout << "e in the " << x << " power: " << counter << std::endl;
    }
    
    return 0;
}


long long factorial(int num)
{
    if (num > 0)
        return num * factorial(num - 1);
    else
        return 1;
}