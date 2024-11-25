#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double hx = 0.1;
    double start = 0.3;
    double end = 5;
    int result = 0;

    for (double x = start; x <= end; x += hx)
    {
        double y = pow(cos(x), 2) * exp(-x);
        if (y < 0)
        {
            result++;
        }
    }

    cout << "Результат: " << result << endl;
    return 0;
}