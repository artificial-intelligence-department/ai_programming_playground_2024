#include <iostream>
#include <cmath> 
using namespace std;
int main() {
    double x; // Тут є x
    cout << "What is x: ";
    cin >> x; 
    double y = 0.0; // Тут є y
    // Обчислення суми
    for (int i = 1; i <= 10; ++i) {
        y += pow(x, i) / i; 
    }
    // Тут є результат
    cout << "y = " << y << endl;

    return 0;
}
