#include <iostream>
#include <cmath>  
using namespace std;


double calculateLn(double x) {
    return log(x);  
}
double calculateLog(double x) {
    return log10(x);  
}

int main() {
    double number;

    cout << "Введіть число для обчислення натурального логарифму: ";
    cin >> number;
    cout << "Натуральний логарифм числа " << number << " дорівнює: " << calculateLn(number) << endl;

    cout << "\nВведіть число для обчислення десяткового логарифму: ";
    cin >> number;
    cout << "Десятковий логарифм числа " << number << " дорівнює: " << calculateLog(number) << endl;

    return 0;
}
