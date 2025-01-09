#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double x[7];
    double h = 0.5;
    double y, z;

    for(int i = 0; i<size(x); i++){
        x[i] = 1 + h * i;
        z = fabs(x[i]) + pow(x[i], 3);
        y = z * (sin(pow((2 + x[i]), 2))/(2 + x[i]));
        
        cout<<fixed<<setprecision(4);
        cout<<"x"<<i+1<<" = "<<x[i]<<"   "<<"z"<<i+1<<" = "<<z<<"   "<<"y"<<i+1<<" = "<<y<<endl;
    }

    return 0;
}