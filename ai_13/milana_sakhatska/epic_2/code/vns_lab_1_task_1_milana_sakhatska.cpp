#include <iostream>  
#include <cmath>     

float calculateWithFloat(float a, float b) {
   
    float numerator = pow(a + b, 3) - (pow(a, 3) - 3 * a * pow(b, 2)); 
    float denominator = pow(b, 3) - 3 * pow(a, 2) * b;               
    return numerator / denominator; 
}


double calculateWithDouble(double a, double b) {
   
    double numerator = pow(a + b, 3) - (pow(a, 3) - 3 * a * pow(b, 2)); 
    double denominator = pow(b, 3) - 3 * pow(a, 2) * b;                 
    return numerator / denominator; 
}

int main() {
  
    float a_float = 1000.0f, b_float = 0.001f;
    double a_double = 1000.0, b_double = 0.001;
    


    float result_float = calculateWithFloat(a_float, b_float);
    std::cout << "Результат з використанням float: " << result_float << std::endl;

  
    double result_double = calculateWithDouble(a_double, b_double);
    std::cout << "Результат з використанням double: " << result_double << std::endl;

    return 0;
}
