#include <iostream>

using namespace std;

int main(){
    long long int H, M, h1, m1, h2, m2, h3, m3,m4,h4;
    cin>>H>>M;
    cin>>h1>>m1;
    cin>>h2>>m2;
    cin>>h3>>m3;
    m4=m1+m2+m3;
    h4=h1+h2+h3;
    if((h1>0 && m1>0) || (h2>0 && m2>0) || (h3>0 && m3>0)){
        cout<<"NO"<<endl;
    }else if(H-h4>0 && M-m4>0){
            cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}