#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float step = 0.5;
    int start = -4;
    int end = 4;
    for(float i=start; i<=end; i += step){
        float y = 2*pow(i,2) - 5*i - 8;
        cout<<y<<"\t";
        }
    return 0;
}
