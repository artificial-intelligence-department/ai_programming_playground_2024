#include <iostream>

using namespace std;

float Summ(float num1, float num2)
{
    return num1 + num2;
}

double Summ(double num1, double num2)
{
    return num1 + num2;
}

int main()
{
    float a = 0.7, b = 0.063;
    double x = (2.0 / 5.0), y = (8.0 / 13.0);

    float resultF = Summ(a, b);
    double resultD = Summ(x, y);

    cout << "Результатом додавання десяткових дробів " << a << " і " << b << " є: " << resultF << endl;
    cout << "Результатом додавання звичайних дробів 2/5 і 8/13 є: " << resultD << endl;

    return 0;
    
}