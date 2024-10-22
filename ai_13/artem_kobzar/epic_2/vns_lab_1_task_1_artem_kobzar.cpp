#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string input;
    do {
       cout<<"Enter f or d: "; 
       cin>>input;
    } while (input !="f" && input !="d");
    if (input =="d"){
      double a1 = 100;
    double b1 = 0.0001;
    double c1 = pow(a1+b1,4);
    double d1= pow(a1,4)+4*pow(a1,3)*b1+6*pow(a1,2)*pow(b1,2);
    double e1 = 4*a1*pow(b1,5)+pow(b1,4);
    double f1 = c1-d1;
    double h1 = f1/e1;
    cout<<"The result of double is: "<<h1;  
    } else {
       float a2 = 100;
    float b2 = 0.0001;
    float c2 = pow(a2+b2,4);
    float d2= pow(a2,4)+4*pow(a2,3)*b2+6*pow(a2,2)*pow(b2,2);
    float e2 = 4*a2*pow(b2,5)+pow(b2,4);
    float f2 = c2-d2;
    float h2 = f2/e2;
    cout<<"The result of float is: "<<h2; 
    }
    return 0;
}