#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    double a = M_PI/5;
    double b = M_PI;
    double k = 10;
    double step = (b-a)/k;
    vector<double> x(k+1);
    vector<double> y1;
    for (int i=0; i<=k; i++)
    {
        x[i] = a+step*i;
        double val1=(pow(M_PI,2)/8)-(M_PI/4)*fabs(x[i]);
        y1.push_back(val1);
    }
    vector<double> y2;
    double sum;
    for (int i=0; i<=k; i++)
    {
        sum = 0;
        for (int j=1; j<=40; j++)
        {
            double val2=cos((2*j-1)*x[i])/pow(2*j-1,2);
            sum+=val2;  
        }
        y2.push_back(sum);
    }
    vector<double> y3;
    for (int i=0; i<=k; i++)
    {
        sum = 0;
        double val3 = 1;
        int n = 1;
        do
        {
            val3=cos((2*n-1)*x[i])/pow(2*n-1,2);
            sum+=val3;
            n++;
        } while (val3 > 0.0001);
        y3.push_back(sum);
    }
    for (int i=0; i<=k; i++)
    {
        cout << x[i] << " " << y1[i] << " " << y2[i] << " " << y3[i] << endl;
    }
}