#include <math.h>
#include <iostream>
using namespace std;
#define e 2.71

float Count (float a, float b, float x){
    float c=(b*pow(x, 2))/(pow(e, a*x)-1);
    float S;
    float r1=pow((x+b), 2);
    float r2=pow(tan(r1), 2);
    S = (pow(x, 3)*r2+a)*c/pow((x+b), 0.5);
    cout<<"result: "<<S;
    return S;
}

int main(){
    Count(16.5, 3.4, 0.61);
    return 0;
}