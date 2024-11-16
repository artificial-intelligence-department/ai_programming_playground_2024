#include <iostream>
using namespace std;

const double epsilon = 0.0001;

//використовую рекурсивну функцію для обчислення суми ряду
double calculateSum(double term, int n, double sum) {
    if (term < epsilon) {
        return sum;
    }
    term = term * static_cast<double>(n) / (2 * n * (2 * n - 1)); //новий член ряду
    return calculateSum(term, n + 1, sum + term);
}

int main() {
    double sum = 1.0;
    double term = 1.0; 
    int n = 1;

    sum = calculateSum(term, n, sum);

    cout << "Сума ряду з точністю " << epsilon << " дорівнює: " << sum << endl;
    return 0;
}
