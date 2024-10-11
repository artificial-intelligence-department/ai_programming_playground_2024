#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int choice_of_type;
    cout<<"Який тип даних хочете вводити?"<<endl;
    cout<<"1. float"<<endl<<"2. double"<<endl;
    cin>>choice_of_type;
    cout<<endl;

    switch(choice_of_type){
        case 1:
            float a;
            float b;
            cout<<"Введіть значення а: ";
            cin>>a;
            cout<<"Введіть значення b: ";
            cin>>b;
            float a1; float a2; float a3; float a4; float a5; float a6;
            a1=pow(a+b,4);
            a2=pow(a,4);
            a3=4*b*pow(a,3);
            a4=6*pow(a*b, 2);
            a5=4*a*pow(b, 3);
            a6=pow(b, 4);
            float result;
            result=(a1-(a2+a3+a4))/(a5+a6);
            cout<<"Результат: "<<result;
            break;
        case 2:
            double x;
            double y;
            cout<<"Введіть значення а: ";
            cin>>x;
            cout<<"Введіть значення b: ";
            cin>>y;
            double res;
            double x1; double x2; double x3; double x4; double x5; double x6;
            x1=pow(x+y,4);
            x2=pow(x,4);
            x3=4*y*pow(x,3);
            x4=6*pow(x*y, 2);
            x5=4*x*pow(y, 3);
            x6=pow(y, 4);
            res=(x1-(x2+x3+x4))/(x5+x6);
            cout<<"Результат: "<<res;
            break;
       
        default: cout<<"Некоректне значення";
    }
    return 0;
}