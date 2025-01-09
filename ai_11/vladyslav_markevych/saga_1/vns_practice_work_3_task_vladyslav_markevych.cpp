#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int R, H;
    double V;
    cout<<"Введіть початкові дані:"<<endl;
    cin>>R;
    cin>>H;

    V = H*M_PI*pow(R,2)/3;

    cout<<"Об'єм циліндра: "<<V<<" см.куб."<<endl;


    int R1,R2,R3;
    cout<<"Введіть початкові дані:"<<endl;
    cin>>R1>>R2>>R3;
    int total = R1+R2+R3;

    cout<<"Опір електричного струму: "<<total;
    return 0;
}