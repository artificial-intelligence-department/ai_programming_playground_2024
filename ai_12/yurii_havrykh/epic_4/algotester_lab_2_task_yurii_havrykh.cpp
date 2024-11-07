#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x,y,z;
    cin>>n;
    vector<int> a(n),b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x>>y>>z;
    for(int i=0;i<n;i++){
        if ((a[i]!=x)&&(a[i]!=y)&&(a[i]!=z))
            b.push_back(a[i]);
    }
    int m=b.size();
    cout<<max(0,m-1)<<endl;
    for(int i=0;i<m-1;i++){
        cout<<b[i]+b[i+1]<<" ";
    }
}

