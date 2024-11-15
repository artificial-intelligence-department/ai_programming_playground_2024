#include <iostream>
#include <cmath>
using namespace std;

int factorial(int b) {
    int result = 1;
    for (int i = 1; i <= b; i++) {
        result *= i;
    }
    return result;
}

int main() {
    double epsilon = 0.0001;
    int n=1;
    double sum=0.0;
    double a_n;
    do {
        double a=pow(n,3);
        double b=3*n-3;
        double c=a/factorial(b);
        a_n=1.0/c;
        sum +=a_n;
        n++;
    } while(fabs(a_n) >= epsilon);
    cout << "Sum equals: "<<sum;
    return 0;
}