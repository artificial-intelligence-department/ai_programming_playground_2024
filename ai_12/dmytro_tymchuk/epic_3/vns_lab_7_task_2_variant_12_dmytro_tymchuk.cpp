#include<iostream>
using namespace std;

double division (double num_1, double num_2)
{
    printf("%.2lf : %.2lf = %.2lf\n",num_1, num_2, num_1 / num_2);
    return 0;
}
double division (double numerator_1, double numerator_2, double denominator_1, double denominator_2)
{
    printf("%.lf/%.lf : %.lf/%.lf = %.2lf\n",numerator_1, denominator_1, numerator_2, denominator_2, 
            (numerator_1 * denominator_2) / (numerator_2 * denominator_1));

    return 0;
}

int main()
{
    double num_1, num_2;
    cout<<"Введіть перше число: ";
    cin>>num_1;
    cout<<"Введіть друге число: ";
    cin>>num_2;
    division(num_1, num_2);
    
    double numerator_1, numerator_2, denominator_1, denominator_2;
    cout<<"Введіть чисельник першого дробу: ";
    cin>>numerator_1;
    cout<<"Введіть знаменник першого дробу: ";
    cin>>denominator_1;
    cout<<"Введіть чисельник другого дробу: ";
    cin>>numerator_2;
    cout<<"Введіть знаменник другого дробу: ";
    cin>>denominator_2;

    division(numerator_1, numerator_2, denominator_1, denominator_2);
    return 0;
}