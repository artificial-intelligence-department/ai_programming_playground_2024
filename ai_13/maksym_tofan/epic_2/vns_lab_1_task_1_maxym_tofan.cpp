#include <iostream>
#include <cmath>

using namespace std;

// Template function to perform operations on two numbers of any type (float or double)
template <typename T>
T operations(T a, T b) {
    T t1 = a - b;
    T t2 = pow(t1, 4);               // (a - b)^4
    T t3 = pow(a, 4);                 // a^4
    T t4 = 4 * pow(a, 3) * b;         // 4 * a^3 * b
    T t5 = 6 * pow(a, 2) * pow(b, 2); // 6 * a^2 * b^2
    T t6 = 4 * a * pow(b, 3);         // 4 * a * b^3
    T t7 = pow(b, 4);                 // b^4
    
    T numerator = t2 - t3 + t4;       // (a - b)^4 - a^4 + 4 * a^3 * b
    T denominator = t5 - t6 + t7;     // 6 * a^2 * b^2 - 4 * a * b^3 + b^4
    
    T result = numerator / denominator;
    return result;
}

int main() {
    // Define float and double variables
    float f_a = 100.0f, f_b = 0.001f;
    double d_a = 100.0, d_b = 0.001;

    // Perform operations and get results for float and double types
    float float_result = operations(f_a, f_b);
    double double_result = operations(d_a, d_b);

    // Display the results
    cout << "Float result: " << float_result << endl;
    cout << "Double result: " << double_result << endl;

    // The difference in results occurs due to precision limitations of the float type compared to double.
    return 0;
}
