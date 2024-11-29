//task 2 V-19
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int count = 0;
    double a, b, h;

    cout<<"Введіть ліву межу для х: ";
    cin>>a;
    cout<<"Введіть праву межу для x: ";
    cin>>b;
    
    cout<<"Введіть крок для x: ";
    cin>>h;

    for (double i = a; i <= b; i += h)
    {
        if (cos(pow(i, 2)) * exp(-i) < 0) count++;
    }
      
    cout<<"Кількість значень менших за 0: "<<count<<endl;

    return 0;
}