#include <iostream>
#include <math.h>

int main(){
    float x = 1.23;
    float y = 0.79;
    float b = 1 + tan(x/2) * tan(x/2);
    float a = y + x/(y*y*y + abs(x*x/(y + cbrt(x*x))));
    std::cout << a;
    return 0;
}