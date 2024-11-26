#include <iostream>
#include <cmath>

using namespace std;

double row(double x, int n){
    double sum = 0.0;
    double term = 1.0;
    for (int i = 0; i<n; i++){
    sum += term;
    term *= -x * x/((2 * i + 1)* (2*i+2));
    }
return sum;
}
double rowwithepsilon(double x, double epsilon){
    double sum = 0.0;
    double term = 1.0;
    int i = 0;
    while(fabs(term) >= epsilon){
        sum += term;
        i++;
        term *= -x * x/((2*i - 1)*(2 * i));
    }
    return sum;
}

int main(){
    int n, k=10;
    double epsilon = 0.0001;
    double a, b, step;

    cout << "Введіть початок діапазону a: ";
    cin >> a;
    cout << "Введіть кінець діапазону b: ";
    cin >> b;
    cout << "Введіть кількість членів ряду n: ";
    cin >> n;


    step = (b-a)-k;

     cout << "Результати для фіксованого n:\n";
    for (int i = 0; i <= k; i++) {
        double x = a + i * step;
        double resultN = row(x, n);
        cout << "cos(" << x << ") ≈ " << resultN << " (n = " << n << ")\n";
    }

    cout << "\nРезультати для заданої точності epsilon = " << epsilon << ":\n";
    for (int i = 0; i <= k; i++) {
        double x = a + i * step;
        double resultEps = rowwithepsilon(x, epsilon);
        cout << "cos(" << x << ") ≈ " << resultEps << " (epsilon = " << epsilon << ")\n";
    }
    
    return 0;
}