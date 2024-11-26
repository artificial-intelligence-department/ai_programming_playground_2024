#include <iostream> 
#include <cmath>

using namespace std;
//юзаю перевантаження ф-ї
double fractionsSubtract(double fract1, double fract2)
{
    return fract1 - fract2;
}

//юзаю перевантаження ф-ї
double fractionsSubtract(int numerator1, int denominator1, int numerator2, int denominator2)
{
    double fract1 = (double)numerator1 / denominator1;
    double fract2 = (double)numerator2 / denominator2;
    return fractionsSubtract(fract1, fract2);
}

int main()
{
    cout << "Віднімання десяткових дробів: " << fractionsSubtract(0.5, 0.2) << endl;
    cout << "Віднімання звичайних дробів: " << fractionsSubtract(3,5,1,2) << endl;
    return 0;
}
