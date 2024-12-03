#include <iostream>
#include <algorithm>

using namespace std;

void function_1() 
{
    float a, b;
    int c, d, e;
    double f;

    cout << "Введіть два дійсних числа: " << "\n";
    cin >> a >> b;
    cout << "Введіть три цілі числа: " << "\n";
    cin >> c >> d >> e;
    cout << "Введіть одне дійсне число з подвійною точністю: " << "\n";
    cin >> f;

    float min1;

    if(a > b)
    {
        min1 = b;
    }
    else if(a < b)
    {
        min1 = a;
    }
    cout << "Min element in float is: " << min1 << "\n";

    float max1;

    if(a > b)
    {
        max1 = a;
    }
    else if(a < b)
    {
        max1 = b;
    }
    cout << "Max element in float is: " << max1 << "\n";

    int min2;

    if(c > d || c > e)
    {
        if(d > e)
        {
            min2 = e;
        }
        else if(d < e)
        {
            min2 = d;
        }
    }
    else if(c < d || c < e)
    {
        min2 = c;
    }
    else if(d > c || d > e)
    {
        if(c < e)
        {
            min2 = c;
        }
        else if(c > e)
        {
            min2 = e;
        }
    }
    else if(d < c || d < e)
    {
        min2 = d;
    }
    else if(e < d || e < c)
    {
        min2 = e;
    }
    else if(e > d || e > c)
    {
        if(d < c)
        {
            min2 = d;
        }
        else if(d > c)
        {
            min2 = c;
        }
    }
    cout << "Min element in int is: " << min2 << "\n";

    int max2;

    if(c < d || c < e)
    {
        if(d > e)
        {
            max2 = d;
        }
        else if(d < e)
        {
            max2 = e;
        }
    }
    else if(c > d || c > e)
    {
        max2 = c;
    }
    else if(d < c || d < e)
    {
        if(c < e)
        {
            max2 = e;
        }
        else if(c > e)
        {
            max2 = c;
        }
    }
    else if(d > c || d > e)
    {
        max2 = d;
    }
    else if(e < d || e < c)
    {
        min2 = e;
    }
    else if(e > d || e > c)
    {
        if(d < c)
        {
            min2 = d;
        }
        else if(d > c)
        {
            min2 = c;
        }
    }
    cout << "Min element in int is: " << min2 << "\n";

    int number = {a, b, c, d, e, f};
    sort(number.begin(), number.end());
    double sumMin = *number[0] + *number[1] + *number[2];
    double sumMax = *number[3] + *number[4] + *number[5];

    double result;
    if(sumMax > sumMin*2)
    {
        sumMax * sumMin;
    }
    else if(sumMax > sumMin*3)
    {
        sumMax / sumMin;
    }
    else if(sumMax > sumMin*4)
    {
        sumMax + sumMin;
    }
}



int main()
{
    int variant = 51;

    return 0;
}

