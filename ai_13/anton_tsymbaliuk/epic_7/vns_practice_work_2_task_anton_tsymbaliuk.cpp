#include <iostream>
#include <math.h>

int main(){
    float x = -3.0;
    float step = 0.5;
    float a = 5.3;
    float y = 1.1;
    while(x <= 3){
        std::cout << "x: " << x << std::endl;
        if(x*x + y*y <= a *a) std::cout << (x / (15 * x*x)) << std::endl; //When x = 0 there will be nan caused by division by 0
        else std::cout << (x*x + exp(x)) << std::endl;
        x+= step;
    }
    return 0;
}