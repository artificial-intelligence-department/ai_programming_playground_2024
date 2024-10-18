#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>rez(N,0);
vector<vector<pair<int,int>>> tree(N);

void dfs(int v, int par){

    for (auto edge: tree[v]) {
        int u=edge.first,w=edge.second;
        if(u!=par){
            rez[u]=min(rez[v],w);
            dfs(u, v);
        }
    }
}

int main(){
    int n,a,b,from,to,wei;
    cin>>n>>a>>b;
    a--;
    b--;
    for(int i=0;i<n-1;i++){
        cin>>from>>to>>wei;
        tree[from-1].push_back({to-1,wei});
        tree[to-1].push_back({from-1,wei});

    }
    rez[a]=1e9;
    dfs(a,-1);
    cout<<rez[b]<<endl;
}

