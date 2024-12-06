#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Тут дані змінних
    double b = 15.5, x = -2.9, a = 1.5;
    
    // Тут y шукаю
    double y = pow(cos(pow(x, 3)), 2) - (x / sqrt(pow(a, 2) + pow(b, 2)));
    
    // Тут P шукаю
    double P = sqrt(pow(x, 2) + b) - pow(b, 2) * pow(sin(x + a), 3) / (x * y);
    
    // Тут результат виводжу
    cout << "y = " << y << endl;
    cout << "P = " << P << endl;
    // Тут просто коментар
    return 0;
}
