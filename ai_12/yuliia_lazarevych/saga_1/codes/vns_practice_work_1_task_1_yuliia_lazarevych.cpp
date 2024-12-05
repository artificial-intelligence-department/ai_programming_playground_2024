//a=(√(|x+1| )-√y)/(1+x^2/2+y^2/4); b=ctge^(x+3). 

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    long double a, a1h, a2h, a3l;
    a1h=sqrt(fabs(x + 1));
    a2h=sqrt(y);
    a3l=1 + (pow(x,2)/2) + (pow(y,2)/4);
    a=(a1h - a2h) / a3l;
    cout << a << endl;

    long double b, b1, b2;
    b2=exp(x+3);//е
    b=1/tan(b2);
    cout << b << endl;
    return 0;
}