#include <iostream>

int main(){
    
    float a = 1000; // точнісь 7 знаків після коми
    double b = 0.0001; // точність 15-16 знаків після коми
    bool isFirst = true;
    while(true){
        if(!isFirst){
            std::cout << "Enter a and b: ";
            std::cin >> a >> b;
        }
        else isFirst = false;
        
        double sum1 = a + b;
        sum1 *= sum1;   //піднесення до 2-го степення
        double sum2 = a * a + 2 * a * b;
        float numerator = sum1 - sum2;
        double denominator = b * b;
        double result = numerator / denominator; // через різницю з точністю в float і double(і інколи через похибку в double при малих дробових числах), результат не завжди 1
        std::cout << "Result: " << result << std::endl;
    }
    


}