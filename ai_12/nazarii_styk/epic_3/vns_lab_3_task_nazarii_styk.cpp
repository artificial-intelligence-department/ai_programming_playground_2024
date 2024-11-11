// Варіант 19
#include <iostream>

int main()
 {
    double x = 1.0; 
    double epsilon = 0.000001; 
    double term = 1.0; 
    double sum = term; 
    int n = 1; 
    
    // Обчислюємо суму ряду доти, доки доданок більше за точність
    while (term > epsilon || -term > epsilon)
     { 
        term *= (2 * x) / n;
        sum += term; 
        n++; // збільшуємо факторіал
    }
    
    std::cout << "Сума ряду для e^(2x) при x = " << x << " дорівнює: " << sum << std::endl;

    return 0;
}
