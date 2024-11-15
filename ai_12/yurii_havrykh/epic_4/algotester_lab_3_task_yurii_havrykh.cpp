#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    vector<int>a(n),c(n),d;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[i]=a[i];

    }
    cin>>m;
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
        bool flag=true;
        for(int j:c){
            if (j==b[i]) flag=false;
        }
        if (flag) c.push_back(b[i]);
    }
    for(int cur_element:c){
        bool in_a = false, in_b = false;
        for(int i:a){
            if (i==cur_element) in_a=true;
        }
        for(int i:b){
            if (i==cur_element) in_b=true;
        }
        if ( (in_a) && (in_b) ) d.push_back(cur_element);
    }
    cout<<d.size()<<endl<<c.size();
    
}