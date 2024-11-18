#include <iostream>
#include <math.h>
using namespace std;

float CountSquare(){
    float x1, y1, x2, y2, x3, y3;
    cout<<"x1, y1 > ";
    cin>>x1>>y1;
    cout<<endl;
    cout<<"x2, y2 > ";
    cin>>x2>>y2;
    cout<<endl;
    cout<<"x3, y3 > ";
    cin>>x3>>y3;
    cout<<endl;
    float a1, a2, a3, p;
    a1=sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    a2=sqrt(pow((x3-x2), 2) + pow((y3-y2), 2));
    a3=sqrt(pow((x3-x1), 2) + pow((y3-y1), 2));
    p=(a1+a2+a3)/2;
    float S=sqrt(p*(p-a1)*(p-a2)*(p-a3));
    cout<<S;
}

int main(){
    CountSquare();
    return 0;
}