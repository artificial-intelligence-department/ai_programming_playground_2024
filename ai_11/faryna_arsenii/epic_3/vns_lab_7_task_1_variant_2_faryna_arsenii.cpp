#include <iostream>
#include <cstdarg>
#include <iomanip>

using namespace std;

float mult (int count, float first, ...){
    va_list arguments;
    va_start (arguments, first);

    float res = first;

    for (int i = 1; i < count; i++){
        double next = va_arg(arguments, double);
        res *= static_cast<float>(next);
    }
    va_end(arguments);

    return res;

}

int main(){
    cout << fixed << setprecision(2);
    float case1 = mult(3 ,8.f, 5.f, 4.f);
    cout << case1 << endl;
    float case2 = mult(7, 45.f, 0.8, 34.f, 1.23, 52.f, 3.f, 5.f);
    cout << case2 << endl;
    float case3 = mult(11, 4.5, 34.f, 2.45, 76.f, 3.f, 6.f, 90.f, 5.f, 43.f, 1.f, 16.f);
    cout << case3 << endl;

    return 0;
}