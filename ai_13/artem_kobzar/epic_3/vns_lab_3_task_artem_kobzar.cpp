#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double initial_function(double x) {
    return 0.5-(M_PI/4)*fabs(sin(x));
}
double sum_w_fixed_n(double x,int n) {
    double sum=0.0;
    for(int i=1; i<=n;i++) {
        sum +=cos(2*i*x)/(4*pow(i,2)-1);
    }
    return sum;
}
double sum_w_epsilon(double x, double epsilon) {
    double sum=0.0;
    double j=1;
    double a=cos(2*j*x)/(4*pow(j,2)-1);
    do {
        sum +=a;
        j++;
        a=cos(2 * j * x) / (4 * pow(j, 2) - 1);
    } while (fabs(a)>epsilon);
    return sum;
}
int main() {
    double epsilon=0.0001;
    double a=0.1;
    double b=0.8;
    int n=50;
    int k=10;
    double step=(b-a)/k;
    
    for (int m=0;m<=k;m++) {
        double x=a+m*step;
        double exact_Value=initial_function(x);
        double sum_N=sum_w_fixed_n(x,n);
        double sum_Epsilon=sum_w_epsilon(x,epsilon);
        cout << fixed << setprecision(6) << x<<"\t"
             << exact_Value << "\t"
             << sum_N << "\t"
             << sum_Epsilon << endl;
    }
    return 0;
}