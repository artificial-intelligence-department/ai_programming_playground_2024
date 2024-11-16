#include <iostream>
#include <cmath>

using namespace std;

int main(){

long double x,y,s_1 = 0,s_2 = 0,k;
int n;


for(x = 0.1;x<=0.8;x+=0.07){
    y = x*atan(x)-log(sqrt(pow(x,2)+1));
    for(n = 1;n<=10;n++){
        k = pow(-1,n+1)*pow(x,2*n)/(2*n*(2*n-1));
        s_1+=k;
    
    }
    n = 1;
    do {
        k = pow(-1,n+1)*pow(x,2*n)/(2*n*(2*n-1));
        s_2 += k;
        n++;
        } while (fabs(k) > 0.0001);
    cout <<"x = "<<x<<" SN = "<<s_1<<" SE = "<<s_2<<" y = "<<y<<endl;
    s_1 = 0;
    s_2 = 0;
}




    return 0;
}