#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n){
    double result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    } 
    return result;
} 

int main(){
int n = 10;
float x = 0.2;
double y;
double sum;

y = (exp(x) + exp(-x))/2;
cout << y << endl;

for(int n = 10; n >= 1; n--){           // при n = 10
sum += (pow(x,2*n))/factorial(2*n);
}

double sum1;
double prevsum;
n = 1;
do{
    prevsum = sum1;                     // коли різниця між елементами менше за 0.0001
    sum1 += (pow(x,2*n))/factorial(2*n);
    n++;
} while(abs(prevsum - sum1) >= 0.0001);


cout << sum+1 << endl;
cout << sum1+1 << endl;
    return 0;
}
