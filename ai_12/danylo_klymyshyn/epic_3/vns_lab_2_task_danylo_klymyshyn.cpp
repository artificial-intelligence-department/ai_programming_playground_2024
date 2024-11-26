#include <iostream>
#include <cmath>



int main(){

double a;
double S = 0;
for(int i = 2;i < 17; ++i){
    a = pow(i, log(i))/pow(log(i), i);
    S+=a;

}

std::cout << "S = " << S;

    return 0;
}