// Vns task 1 V-12
#include<iostream>
#include<math.h>
using namespace std;

namespace Math{
    double numerator(double x, double y, double a, double b)
    {
        return pow(sin(a * pow(x, 3) + b * pow(y, 2) - a * b), 3);//обчислення чисельника
    }

    double denominator (double x, double y, double a, double b)//обчислення знаменник
    {
        return pow( pow((a * pow(x, 3) + b * pow(y, 2) - a), 2) + M_PI, (1.0 / 3.0)  );
    }

    double tangens (double x, double y, double a, double b)//обчислення тангенса
    {
        return tan(a * pow(x, 3) + b * pow(y, 2) - a * b);
    }
}
int main()
{
    double a, b, x, y;
    cout<<"Введіть числа у вираз: "<<endl;

    cout<<"x = ";
    cin>>x;

    cout<<"y = ";
    cin>>y;

    cout<<"a = ";
    cin>>a;

    cout<<"b = ";
    cin>>b;

    double p = 0;

    
    p = abs (Math::numerator(x, y, a, b) / Math::denominator(x, y, a, b)) + Math::tangens(x, y, a, b);

    printf("Результат обчислень: %.4lf", p);
    return 0;
}