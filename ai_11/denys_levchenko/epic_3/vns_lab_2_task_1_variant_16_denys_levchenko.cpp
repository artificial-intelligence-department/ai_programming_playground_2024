#include <iostream>
#include <cmath>

using namespace std;

int main(){
    const double epsilon = 0.0001;
    double sum = 0.0;
    double term;
    int n = 1;
    do {
        term = log10(tgamma(n+1)) * exp((-n)*sqrt(n));
        sum += term;
        n++;
    } while (fabs(term) >= epsilon);
    cout << sum << endl;
}