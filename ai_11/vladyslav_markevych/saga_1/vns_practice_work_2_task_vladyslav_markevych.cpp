#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    double hx = 0.2;
    int x_start = 1;
    int x_end = 2; 
    vector<int> b = {2,4,6,8};
    for(int value : b){
        for(double x = x_start; x <= x_end; x +=hx){
            double z = (sqrt(4*value+pow(x,2)))/2;
            double y = exp(x/2)*pow(value,x)*(cos(z)+sin(z));
            cout<<z<<"\t"<<y<<"\t"<<endl;
        }
    }
    return 0;
}