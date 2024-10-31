#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 100;
    double b = 0.001;

    double result1 = ( pow ( a - b , 4 ) - ( pow ( a , 4 ) - ( 4 * pow( a , 3 ) * b ) ) ) / 
    ( ( 6 * a * a * b * b ) -  4 * a * pow ( b , 3 ) + pow( b , 4 )  );

    float result2 = ( pow ( a - b , 4 ) - ( pow ( a , 4 ) - ( 4 * pow( a , 3 ) * b ) ) ) / 
    ( ( 6 * a * a * b * b ) -  4 * a * pow ( b , 3 ) + pow( b , 4 )  );

    printf("double: %.18lf \nfloat:  %.18f",result1,result2);
}