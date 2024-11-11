#include <iostream>
#include <cmath>

using namespace std;
const double PI = 3.1415;

double exactValueOfx(double x){
    return (x*sin(PI/4)) / (1 - 2*x*cos(PI/4) + pow(x,2));
}

double sumForGivenN(double x, int n){
    double sum = 0.0;
    for(int k = 1; k <= n; k++){
        sum = pow(x,k) * sin(k) * PI/4 ;
    }
    return sum;
}

double sumPrecision(double x, double epsilon){
    double sum = 0.0;
    double a = 0.0;
    int k = 1;
    do{
        a = pow(x,k) * sin(k) * PI/4 ;
        sum += a;
        k++;
        } while (abs(a) > epsilon);
        return sum;
}

int main(){
    double a = 0.1;
    double b = 0.8;
    int k = 10;
    int n = 40;
    double epsilon = 0.0001;
    double step = (b - a) / k;

    for (double x = 0; x >= a, x <= b; x+= step){
        double exactValue = exactValueOfx(x);
        double sumForN = sumForGivenN(x, n);
        double precisionSum = sumPrecision(x, epsilon);
        cout << "X= " << x << "   SN= " << exactValue <<  "   SE= "<< sumForN << "   Y= " << sumPrecision << endl;
    }
    return 0;
}