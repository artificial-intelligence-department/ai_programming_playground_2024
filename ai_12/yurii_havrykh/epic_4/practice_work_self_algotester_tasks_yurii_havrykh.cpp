#include <bits/stdc++.h>
using namespace std;

void read_agressive(int n,vector<int> &calm){
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        calm.push_back(x);
    }
}

void read_friend(int m,vector<vector<int>> &g){
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}
void read_fighter(int k, vector<int> &calm, queue<int>  &q){
    int x;
    for(int i=0;i<k;i++){
        cin>>x;
        x--;
        calm[x]=0;
        q.push(x);
    }
}

int dfs(vector<int> &calm, vector<vector<int>> g, queue<int> &q){
    int rez=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto v:g[cur]){
            if (calm[v]==1){
                rez++;
                q.push(v);
            }
            calm[v]=max(calm[v]-1,0);
        }
    }
    return rez;
}


int main() {
    int n1, n2, m1, m2, k1, k2;
    cin>>n1>>n2;
    vector<vector<int>> g1(n1),g2(n2);
    vector<int> calm1,calm2;
    read_agressive(n1,calm1);
    read_agressive(n2,calm2);
    cin>>m1>>m2;
    read_friend(m1,g1);
    read_friend(m2,g2);
    cin>>k1>>k2;
    queue<int> q1, q2;
    read_fighter(k1,calm1,q1);
    read_fighter(k2,calm2,q2);


    int result = dfs(calm1,g1,q1)+dfs(calm2,g2,q2)+k1+k2;
    cout<<result;
}




