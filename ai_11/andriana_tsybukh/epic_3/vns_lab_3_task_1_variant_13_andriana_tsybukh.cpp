#include <iostream>
#include <iomanip>           // setprecision
#include <cmath>
using namespace std;

int main() {
    const double sure = -1e-9;

    // Для визначеного n = 10
    cout << "Для визначеного n = 10 : \n";
    for(double x = 0.2; x <= 1; x += 0.08) {
        double result = 0, n = 10;
        
        for(int i = 0; i <= n; ++i) {
            result += 1.0 / (2 * i + 1) * pow((x - 1) / (x + 1), 2 * i + 1);
            if (result > sure) {
                result = 0;
            }
        }
        cout << "1/2 ln(" << x << ") = " << result << "\n";
    }

    // Для визначеного eps = 0.0001
    cout << "\nДля визначеного eps = 0.0001 : \n";
    for(double x = 0.2; x <= 1; x += 0.08){
        double power = 0, result = 0, i = 0, epsilon = 0.0001;
        power += 0.5 * log(x);

        while (fabs(power-result) >= (epsilon)){
            result += 1 / (2 * i + 1) * pow(((x - 1) / (x + 1)), (2 * i + 1));
            if(result > (-1) * epsilon) {
                result = 0;
            }
            i++;
        }
        cout << "1/2 ln(" << x << ") = " << setprecision(5) << result << "\n";
    }

    // Пряме визначення значення функції
    cout << "\nПряме визначення значення функції : \n";
    for(double x = 0.2; x <= 1; x += 0.08) {
        double result = 0.5 * log(x);
        
        if (result > sure) {
            result = 0;
        }
        cout << "1/2 ln(" << x << ") = " << result << "\n";
    }

    return 0;
}
