#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double sum = 0;

    for (int n = 0; n < 9; n++)
    {
        double a_n = exp(-sqrt(n));
        sum += a_n;
    }

    cout << "Сума перших 9 членів ряду: " << sum << endl;
    return 0;
}