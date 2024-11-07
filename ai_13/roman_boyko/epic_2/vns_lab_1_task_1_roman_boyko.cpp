#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
int ch;
cout<<"Enter float - 1 or double - 2:";
cin>>ch;
if(ch==1){
    float a_f = 1000;
    float b_f = 0.0001;
    float c = pow(a_f-b_f,3);
    float c1 = pow(a_f,3);
    float c2 = 3*a_f*a_f*b_f;
    float c3 = c1 - c2;
    float c4 = c - c3;
    float f = pow(b_f,3);
    float f1 = 3*a_f*b_f*b_f;
    float f2 = f - f1;
    float res1=c4/f2;
    cout<<"Result in float: "<<setprecision(20)<<res1<<endl;
}else if(ch==2){
    double a_d = 1000;
    double b_d = 0.0001;
    double d = pow(a_d-b_d,3);
    double d1 = pow(a_d,3);
    double d2 = 3*a_d*a_d*b_d;
    double d3 = d1 - d2;
    double d4 = d - d3;
    double e = pow(b_d,3);
    double e1 = 3*a_d*b_d*b_d;
    double e2 = e - e1;
    double res2=d4/e2;
    cout<<"Result in double: "<<setprecision(20)<<res2<<endl;
}
else{
    cout<<"Incorrect answer"<<endl;
}

}
