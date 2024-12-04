#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    double y;
    for (float i=-4.0; i<=4.0; i+=0.5){
        y=2*pow(i, 2)-5*i-8;
        cout<<"X = "<<i<<setw(4)<<"\t"<<"Y = "<<y<<endl;
    }
    return 0;
}