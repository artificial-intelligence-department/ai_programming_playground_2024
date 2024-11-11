#include<iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double a = 0.1 , b = 1 , n = 10, k = 10, e = 0.0001, krok = (b-a)/k;


double funct(double x) {
    double func;
    func = sin(x);
    return func;
}

double summaN(double x){
    double s = 0.0;
    for(int i=0; i<n; i++){
        double trans = static_cast<double>(2 * i + 2);
        double vyraz = pow(-1, i) * (pow(x, 2 * i + 1) / tgamma(trans));
        s += vyraz;
    }
    return s;
}

double summaEps(double x) {
    double s = 0.0;
    int i = 0;
    double vyraz;

    do {
        vyraz = pow(-1, i) * (pow(x, 2 * i + 1) / tgamma(static_cast<double>(2 * i + 2)));
        s += vyraz;
        i++;
    } while (abs(vyraz) >= e);

    return s;
}


// tgamma(n+1)


int main(){
    
    cout << fixed <<  setprecision(3);
    for( double i = a ; i <= b; i += krok){
        cout << "X = " << i << "; SN = " << summaN(i) << "; SE = " << summaEps(i) << "; Y = " << funct(i) << endl;    }

    return 0;
}