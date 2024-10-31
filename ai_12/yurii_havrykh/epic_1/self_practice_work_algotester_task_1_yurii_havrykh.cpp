#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a;

float ternary_search(float x){
    double l = -1001, r = 1001;
    double rez=1e5;
    for (int i = 0; i < 64; i++) {
        float m1 = (2 * l + r) / 3;
        float m2 = (l + 2 * r) / 3;
        double dist1 = 0, dist2 = 0;
        for (int j = 0; j < 10; j++) {
            dist1 = max(dist1,sqrt(pow(x - a[j].first, 2) + pow(m1 - a[j].second, 2)));
            dist2 = max(dist2,sqrt(pow(x - a[j].first, 2) + pow(m2 - a[j].second, 2)));
        }
        if (dist1<dist2) r=m2;
        else if (dist2<dist1) l=m1;
        else{
            l=m1;
            r=m2;
        }
        rez=min(rez,min(dist1,dist2));
    }
    return rez;
}

int main(){
    int n=10,x,y;
    float total_result=1e5;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    float lf=-1001,rf=1001;
    for (int i=0;i<64;i++){
        float m1=( 2 * lf + rf)/3;
        float m2=( lf + 2 * rf)/3;
        float dist1= ternary_search(m1);
        float dist2= ternary_search(m2);
        if (dist1<dist2) rf=m2;
        else if (dist2<dist1) lf=m1;
        else{
            lf=m1;
            rf=m2;
        }
        total_result=min(total_result,min(dist1,dist2));
    }
    cout<<total_result;
}


