#include <iostream>
#include <iomanip>
#include <cmath> 

int main() {
    double accuracy = 0.0001;
    double sum = 0.0;
    int n = 1;
    double x; 

    while (true) {
        x = (2 * static_cast<double>(n) - 1) / pow(2, n);

        if (std::abs(x) < accuracy)
            break;

        sum += x;
        n++;
    }
    std::cout << std::fixed << std::setprecision(4) << sum << std::endl;

    return 0;
}
