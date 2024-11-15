// варіант 21
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float a = 100;
    float b = 0.001;

    float c = a-b;
    float d = pow(c, 4); // (a-b)^4

    float e = pow(a, 4); // a^4
    float f = pow(a, 3); // a^3
    float g = 4*f*b;  // 4(a^3)b
    float h = 6*pow(a, 2)*pow(b, 2);  // 6(ab^2)

    float numerator = d - (e - g + h); // (a-b)^4 - (a^4 - 4(a^3)b + 6(ab^2)) (чисельник)     

    float i = pow(b, 4); // b^4
    float j = pow(b, 3); // b^3
    float k = 4*a*j; // 4a(b^3)

    float denominator = i-k; // b^4 - 4a(b^3) (знаменник)
 
    float endRes = numerator/denominator; // кінцевий результат
        
    cout << endRes << endl;

// ----------------------------------------------------------------    
    double a1 = 100;
    double b1 = 0.001;

    double c1 = a1-b1;
    double d1 = pow(c1, 4); // (a-b)^4

    double e1 = pow(a1, 4); // a^4
    double f1 = pow(a1, 3); // a^3
    double g1 = 4*f1*b1;  // 4(a^3)b
    double h1 = 6*pow(a1, 2)*pow(b1, 2);  // 6(ab^2)

    double numerator1 = d1-(e1-g1+h1); // (a-b)^4 - (a^4 - 4(a^3)b + 6(ab^2)) (чисельник)

    double i1 = pow(b1, 4); // b^4
    double j1 = pow(b1, 3); // b^3
    double k1 = 4*a1*j1; // 4a(b^3)

    double denominator1 = i1-k1; // b^4 - 4a(b^3) (знаменник)

    double endRes1 = numerator1/denominator1; // кінцевий результат
        
    cout << endRes1  << endl;
    
    return 0;
}