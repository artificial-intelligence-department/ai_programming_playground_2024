#include <iostream>
#include <cmath>

using namespace std;

int main(){
    const int x = 10; // цілочисельна константа
    double a, b; // дійсний з подвійною точністю змінна
    int y; // цілочисельна змінна
    double chyselnyk, znamennyk;
    cout << "Enter y: ";
    cin >> y;
    chyselnyk = sqrt(abs(x-1))-sqrt(y); // обчислення чисельника використовуючи математичні функції
    znamennyk = 1+(pow(x,2)/2)+(pow(y,2)/4);
    a = chyselnyk/znamennyk;

    b = cos(exp(x+3))/sin(exp(x+3));
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}