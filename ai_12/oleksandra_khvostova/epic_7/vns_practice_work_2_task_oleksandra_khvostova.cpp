#include <iostream>
#include <math.h>
using namespace std;
#define e 2.71

int Count (float x1, float x2, float h){
    int count=0;
    for(float i=x1; i<=x2; i+=h){
        float y=cos(pow(i, 2))*pow(e, (-i));
        if (y<0){
            count+=1;
            }
    }
    cout<<count;
    return count;
}

int main(){
    Count(0.3, 5, 0.1);
    return 0;
}