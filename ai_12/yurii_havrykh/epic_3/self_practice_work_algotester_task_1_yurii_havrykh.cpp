#include <bits/stdc++.h>
using namespace std;

const int N=200001;
int tin[N],tout[N],color[N];
vector<bool> visited(N,false);
vector<bool> visited1(N,false);
vector<vector<int>> graph(N);
vector<vector<int>> vertex_color(N);
vector<vector<int>> vertex_color2(N);
int timee=0;

void dfs1(int v){
    timee++;
    visited[v]=true;
    tin[v]=timee;
    for (auto i:graph[v]){
        if(!visited[i])
            dfs1(i);
    }
    vertex_color[color[v]-1].push_back(v);
    timee++;
    tout[v]=timee;
}
void dfs2(int v){
    visited1[v]=true;
    vertex_color2[color[v]-1].push_back(v);
    for (auto i:graph[v]){
        if(!visited1[i])
            dfs2(i);
    }
}

int main(){
    int n,par;
    cin>>n;
    set<int> colors;
    ;

    for (int i=0;i<n-1;i++){
        cin>>par;
        graph[par-1].push_back(i+1);
    }
    for (int i=0;i<n;i++){
        cin>>color[i];
        colors.insert(color[i]-1);
    }
    dfs1(0);

    dfs2(0);


    for (auto x:colors){
        if (vertex_color[x].size()>1){
            if ((( tin[vertex_color[x][0]]<tin[vertex_color2[x].back()] )&&
                ( tout[vertex_color[x][0]]<tout[vertex_color2[x].back()] )) ||
                (( tin[vertex_color[x][0]]>tin[vertex_color2[x].back()] )&&
                ( tout[vertex_color[x][0]]>tout[vertex_color2[x].back()] ))) {
                cout << "yes" << endl << vertex_color2[x].back()+1 << " " << vertex_color[x][0]+1;
                exit(0);
            }
        }
    }
    cout<<"no";
}

