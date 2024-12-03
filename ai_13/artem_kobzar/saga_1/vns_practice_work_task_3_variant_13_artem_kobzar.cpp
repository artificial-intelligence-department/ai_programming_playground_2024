#include <iostream>
#include <cmath>

using namespace std;

int main() { 
    double r, h, V;
    cout<<"Обчислення об'єму циліндра."<<endl;
    cout<<"Введіть початкові дані: ";
    cin>>r>>h;
    cout<<endl<<"Радіус підставки(см): "<<r;
    cout<<endl<<"Висота циліндра(см): "<<h;
    V = M_PI*pow(r,2)*h;
    cout<<endl<<"Об'єм: " <<V<<" см. куб. "<<endl;
}