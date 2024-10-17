#include <bits/stdc++.h>
using namespace std;

int main() {
    long long H,M,h,m;
    cin>>H>>M;
    bool flag=true;
    for(int i=0;i<3;i++){
        cin>>h>>m;
        H-=h;
        M-=m;
        if((h>0)&&(m>0)) flag=false;
    }
    if ( ( H > 0 ) && ( M > 0 ) && flag)
        cout<<"YES";
    else
        cout<<"NO";
}
