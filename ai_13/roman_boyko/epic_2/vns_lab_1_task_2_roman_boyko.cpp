#include <iostream>

using namespace std;

int main(){
    int m, n;
    cout<<"Enter m: ";
    cin>>m;
    cout<<"Enter n: ";
    cin>>n;
    int res1 = --m - ++n;
    cout<<"m: "<<m<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"Result 1: "<<res1<<endl;
    int res2 = m * n > n++;
    cout<<"m: "<<m<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"Result 2: "<<res2<<endl;
    int res3 = n-- < m++; 
    cout<<"m: "<<m<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"Result 3: "<<res3<<endl;
}