#include <iostream>
#include <cmath> 


using namespace std;

int main() {
    float sum;
    float n = 0;
    for(int i = 0; i < 25; i++){
          float fac = tgamma(n + 1);
          float ex = exp(1);
          float lg = log10(fac);
          float step = -n * pow(n,0.5);
          float result = lg*(ex,step);
          sum += result; 
          n++;
    }
    cout << sum;
    return 0;
}
