#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x=1.2, y=-0.8, s,z;

    s=1+pow(x, 2)/2+pow(x, 3)/3+pow(x, 4)/4;
    z=sin(pow(x, 3))+pow(cos(y), 2);
   
   cout<<"s="<<s<<endl;
   cout<<"z="<<z<<endl;
    return 0;
}