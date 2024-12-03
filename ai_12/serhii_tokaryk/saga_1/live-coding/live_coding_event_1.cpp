#include <iostream>
#include <algorithm>

using namespace std;

float function_1()
{
    float a , b;
    int c , d , e; 
    double f;
    int const v = 56;

    cout << "Введіть два дійсних числа: ";
    cin >> a >> b;
    cout << "Введіть три цілі числа: ";
    cin >> c >> d >> e;
    cout << "Введіть одне дійсне з подвійною точністю число: ";
    cin >> f;

    double arr[] = {(double)a ,(double)b ,(double)c ,(double)d ,(double)e ,(double)f};

    const int n = 6;

    sort(arr, arr + n , greater<double>());

    double bigSum = 0;
    double smallSum = 0;

    for(int i = 0; i < 3;i++)
    {
        bigSum += arr[i];
    }

    for(int i = 3;i < 6; i++)
    {
        smallSum += arr[i];
    }
   
   cout <<"сума 3 найбільших: " << bigSum << endl;
   cout << "сума 3 найменших: " << smallSum << endl;

    double x = 0.0;

   if(bigSum > smallSum * 2)
   {
    x = bigSum * smallSum;
   }

    else if(bigSum > smallSum * 3)
   {
    x = bigSum / smallSum;
   }

    else if(bigSum > smallSum * 4)
   {
    x = bigSum + smallSum;
   }

    return x;
}

int main()
{
cout << "рузультат: " << function_1() << endl;
return 0;
}