#include <iostream>
#include <cmath>

using namespace std;
int main (){
    double a=2, x=1, y, ast=1, xst=0.5;
    while (a <= 10 && x <=8){
        if (a>x) {
            y= pow (a,2)+x;
        } else if (a==x){
            y =  pow (a,2);
        } else {
            y= pow (a,2)-x;
        };
       
        cout << " при x=" << x << " та а=" << a << " y=" << y << endl;
        x += xst;
        a += ast;
    }
}