#include <iostream>
#include <cmath>  // для pow()

int main() {
    double epsilon = 0.0001;  
    double sum = 0.0;  
    double n = 1;  
    double term;  

    do {
        term = n / std::pow((n - 1), 2);

        sum += term;
        n++;
    } while ((term < 0 ? -term : term) > epsilon);  

    std::cout << "Сума ряду з точністю " << epsilon << " дорівнює: " << sum << std::endl;

    return 0;
}
