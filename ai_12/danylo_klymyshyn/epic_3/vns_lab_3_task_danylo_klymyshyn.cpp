#include <iostream>
#include <cmath>
#include <iomanip>

long long factorial(int x){
long long result = 1;
for(int i = 1; i < x+1;i++)
    result*=i;
    return result;
}



int main(){

double a = 0.1, b = 1.0, e = 0.0001;
int k = 35;
double step = (b-a)/k;

std::cout << std::fixed << std::setprecision(4);
        std::cout << std::setw(10) << "x"
                 << std::setw(15) << "y"
                 << std::setw(15) << "S_E" 
                 << std::setw(15) << "S_N"
                 << std::endl;

for(double x = a; x < b; x+=step){
    double temp, S_E = 1, S_N = 1;
    double y = (1-pow(x/2, 2))*cos(x)-(x/2)*sin(x);
    
    for(int n = 1; n < 36; n++){
        temp = pow(-1, n)*(2*pow(n, 2)+1)/factorial(2*n)*pow(x, 2*n);
        S_E += temp;
        if(fabs(temp) < e)
            break;
    }
    long long fact = 1;
    
    for(int n = 1; n < 36; n++){
        fact*=n;
        temp = pow(-1, n)*(2*pow(n, 2)+1)/fact * pow(x, 2*n);
        S_N += temp;
    }
        std::cout << std::setw(10) <<  x << std::setw(15) << y << std::setw(15) << S_E <<  std::setw(15) << S_N << std::endl;
    
}

    return 0;
}