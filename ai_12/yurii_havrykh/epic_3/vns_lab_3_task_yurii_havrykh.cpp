// Variant - 15
#include<bits/stdc++.h>
using namespace std;

float FindFunction(float x){
    float y = (( 1 + (x*x) ) / 2) * atan(x) - ( x/2 );
    return y;
}

float SumForN (float x, int n){
    float sum=0;
    for(int i=1; i<=n; i++){
        float y= ( pow ( -1 , i + 1 ) ) * ( pow ( x , 2 * i + 1 ) / (4 * i * i - 1 ) );
        sum+=y;
    }
    return sum;
}

float SumForEpsilon(float x){
    float epsilon=0.0001;
    float sum=0;
    int i=1;
    float y;
    do{
        y= ( pow ( -1 , i + 1 ) ) * ( pow ( x , 2 * i + 1 ) / (4 * i * i - 1 ) );
        sum+=y;
        i++;
    }while(abs(y)>epsilon);
    return sum;
}

int main(){
    
    int n=30;
    float step = 0.09; // a=0.1 b=1 k=10 --> (1-0.1)/10
    float x=0.1; // a=0.1
    for(int i=0; i<=10; i++){
        float rezN = SumForN(x,n);
        float rezEpsilon = SumForEpsilon(x);
        float y=FindFunction(x);
        printf("x=       %.2f\n",x);
        printf("f(x)=    %f\n",y);
        printf("Sum_n=   %f\n",rezN);
        printf("Sum_eps= %f\n",rezEpsilon);
        printf("-------------------\n");
        x+=step;
    }
}