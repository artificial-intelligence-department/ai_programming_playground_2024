#include <iostream>
#include <cstdio>
#include <cmath>


int main()
{
    int m, n; // m - стовпці, n - рядки


    scanf("%d %d", &m, &n);


    if ((m*n) % 2 == 0)
    {
        printf("Dragon");
    }
    else
    {
        printf("Imp");
    }


    system("pause");
    return 0;
}