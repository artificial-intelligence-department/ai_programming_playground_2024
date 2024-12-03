#include<bits/stdc++.h>
using namespace std;
vector<int>p={0};
vector<int>s={0};
//1220 Каркас мінімальної ваги
void init(int n){
    for(int i=1;i<=n;i++){
        p.push_back(i);
        s.push_back(1);
    }
}
int find(int x){
    if(p[x]==x)
        return p[x];
    else
        return p[x]=find(p[x]);
}

bool unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return false;
    else{
        if(s[x]>s[y]) {
            s[x]+=s[y];
            p[y] = x;
        }
        else{
            s[y]+=s[x];
            p[x]=y;
        }
    }
    return true;
}
struct Edge{
    int v;
    int u;
    int w;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge> graph(m+1);
    for(int i=0;i<m;i++){
        cin>>graph[i].v>>graph[i].u>>graph[i].w;
    }
    sort(graph.begin(),graph.end(), [&](Edge l, Edge r){
       return l.w<r.w;
    });
    init(n);
    long long rez=0;
    for(Edge edge:graph){
        if(unite(edge.v,edge.u)){
            rez+=edge.w;
        }
    }
    cout<<rez;
}