#include <cstdio>
#include <cstdlib>

unsigned long long findLongest(unsigned long long a[]);

int main()
{
    unsigned long long legs[4];
    bool flip = 0;
    for (int i = 0; i < 4; i++)
    {
        scanf("%lld", &legs[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        unsigned long long action;
        scanf("%lld", &action);
        if (action > legs[i])
        {
            printf("ERROR");
            exit(0);
        }
        legs[i] -= action;
        if (legs[i] * 2 <= findLongest(legs))
        {
            flip = 1;
        }
    }
    if (flip == 1)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}

unsigned long long findLongest(unsigned long long a[]) // найбільша помилка в моєму житті
{
    unsigned long long temp = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] > temp)
        {
            temp = a[i];
        }
    }
    return temp;
}
