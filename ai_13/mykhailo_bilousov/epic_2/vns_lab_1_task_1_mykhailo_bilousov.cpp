#include <iostream>
using namespace std;

int main() {
    // ((a-b)^2-(a^2-2ab))/b^2
    float f_a = 1000, f_b = 0.0001;
    cout << "float: " << f_a << " " << f_b << endl;
    float f_ab2 = (f_a-f_b)*(f_a-f_b);
    cout << "float: " << f_ab2 << endl;
    float f_a22ab = f_a*f_a-2*f_a*f_b;
    cout << "float: " << f_a22ab << endl;
    float f_b2 = f_b*f_b;
    cout << "float: " << f_b2 << endl;
    float f_res = (f_ab2-f_a22ab)/f_b2;
    cout << "float: " << f_res << endl;
    
    double a = 1000, b = 0.0001;
    cout << "double: " << a << " " << b << endl;
    double ab2 = (a-b)*(a-b);
    cout << "double: " << ab2 << endl;
    double a22ab = a*a-2*a*b;
    cout << "double: " << a22ab << endl;
    double b2 = b*b;
    cout << "double: " << b2 << endl;
    double res = (ab2-a22ab)/b2;
    cout << "double: " << res << endl;
}