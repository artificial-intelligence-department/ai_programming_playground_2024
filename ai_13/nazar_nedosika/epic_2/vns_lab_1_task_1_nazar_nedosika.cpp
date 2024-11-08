#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
T calculate(T a, T b) 
{
    T t1 = a + b;           // (a + b)
    T t2 = pow(t1, 2);      // (a + b)^2
    T t3 = pow(a, 2);       // a^2
    T t4 = 2 * a * b;       // 2ab
    T numerator = t2 - (t3 + t4);  // (a+b)^2 - (a^2 + 2ab)
    T denominator = pow(b, 2);     // b^2
    T result = numerator / denominator;  // Остаточний результат
    return result;
}

int main() 
{
    float f_a = 1000.0f, f_b = 0.0001f;         //6-9 цифр після коми
    float float_result = calculate(f_a, f_b);
    
    double d_a = 1000.0, d_b = 0.0001;          //15-18 цифр після коми
    double double_result = calculate(d_a, d_b);

    cout << float_result << endl;
    cout << double_result << endl;

    return 0;
}
