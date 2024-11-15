#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int x = 2, y = 4, z = 5; // цілочисельна змінна + константа щоб не можна було змінити
    const double b = 1/tan(exp(x+3)); // дійсна змінна + з подвійною точністю щоб нормально порахувати
    const double a = (sqrt(abs(x-1)) - sqrt(y))/(1 + pow(x,2)/2 + pow(y,2)/4); // математичні функції щоб не писати їх самому
    cout << "b = " << b << endl; 
    cout << "a = " << a << endl;
}