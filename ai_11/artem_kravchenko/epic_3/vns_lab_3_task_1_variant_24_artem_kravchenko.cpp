#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double ryad_n(double x, int n){
double sum = 0;
for (int i = 1; i < n; i++)
{
    sum += pow(-1, i)*(pow((1+x),2*i)/i);
}

return sum;
}

double ryad_epsilon (double x, double epsilon){
    double sum = 0;
    double term;
    int i = 1;
    do
    {
        term = pow(-1, i)*(pow((1+x),2*i)/i);
        sum += term;
        i++;
    } while (fabs(term) >= epsilon);
    return sum;
}

double function (double x){
    double znamenik = 2 + 2*x + pow(x,2);
    if (znamenik <= 0)
    {
        return NAN;
    }
    return log( 1.0 / znamenik);
}

int main (){
    double a = -2;
    double b = -0.1;
    int k = 10;
    double step = (b-a)/k;
    int n = 40;
    double epsilon = 0.0001;

    cout << fixed << setprecision(6);
    cout << "X\t\tSN\t\tSE\t\tY" << endl;

    for (double x = a; x <= b; x += step)
    {
        double sn = ryad_n (x,n);
        double se = ryad_epsilon (x,epsilon);
        double y = function (x);

        cout << x << "\t" << sn << "\t" << se << "\t" << y << endl;
    }
    

    return 0;
}