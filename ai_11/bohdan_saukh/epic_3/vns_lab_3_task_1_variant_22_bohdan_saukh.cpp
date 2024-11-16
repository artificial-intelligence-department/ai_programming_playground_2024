#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n){
    double resault = 1.0;
    for (int i = 1; i <= n; i++){
        resault = resault*i;
    }
    return resault;
}

double function_n(double x, int n){
    double sum = 1.0;
    
    for (int i = 1; i <= n; i++){
        double term = pow(-1, i) * pow(x, 2*i) / factorial(2*i);
        sum += term;
    }

    return sum;
}

double function_epsilon(double x, double epsilon){
    double sum = 1.0;
    double term;
    int i = 1;

    do{
        term = pow(-1, i) * pow(x, 2*i) / factorial(2*i);
        sum = sum + term;
        i++;
    }while (fabs(term) >= epsilon);

    return sum;
}

int main(){
    double a = 1.0, b = 0.1;
    int k = 10;
    int n = 35;
    double epsilon = 0.0001;

    double step = (b - a) / k;
    
    cout << "Сума при n = 35:" << endl;
    for (int i = 0; i <= k; i++){
        double x = a + i * step;
        cout << "f(" << x << ") = " << function_n(x, n) << endl;
    }

    cout << endl << "Сума при ε = 0.0001:" << endl;
    for (int i = 0; i <= k; i++){
        double x = a + i * step;
        cout << "f(" << x << ") = " << function_epsilon(x, epsilon) << endl;
    }

    return 0;
}