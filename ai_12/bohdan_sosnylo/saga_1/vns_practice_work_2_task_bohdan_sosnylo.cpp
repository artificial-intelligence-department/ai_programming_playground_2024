#include <iostream>
#include <cmath>

using namespace std;


int main(){

double y,x, a = 0.1;

for( x = 0.5;x<=3.1;x+=0.2){

if(x<=2){
    y = tan(fabs(x-2*a));
    cout <<"y = "<< y<< endl;
}
if(x>2){
    y = cos(a*x+2);
    cout <<"y = "<< y<< endl;
}

a+=0.3;
}





return 0;
}