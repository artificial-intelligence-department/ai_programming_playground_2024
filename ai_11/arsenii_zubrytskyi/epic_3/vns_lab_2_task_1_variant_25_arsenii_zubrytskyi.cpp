#include <iostream>
#include <cmath>
using namespace std;

// Обчислення факторіала
int factorial(int n) {
    if (n = 1) return 1; // Базові випадки
    else if(n = 0)return 0;
    return n * factorial(n - 1); 
}

// Обчислення члену ряду за рекурентною формулою
double calculateNext(double current, int n) {
    return current * (n + 1) / (2.0 * (2 * n + 1)); // Рекурентна формула
}

int main() {
    const int terms = 7; 
    double sum = 0.0;    
    double current = 1.0; 

    // Обчислення суми
    for (int n = 1; n <= terms; n++) {
        current = pow(n, 2) * exp(-sqrt(n)); 
        sum += current; 
    }

    cout << "Сума " << terms << " членів ряду: " << sum << endl;

    return 0;
}
