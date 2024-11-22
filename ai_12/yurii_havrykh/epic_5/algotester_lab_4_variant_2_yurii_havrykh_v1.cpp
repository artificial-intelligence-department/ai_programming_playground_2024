#include<bits/stdc++.h>
//4.3
using namespace std;

int main(){
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   sort(a.begin(),a.end());
   auto it= unique(a.begin(),a.end());
   a.erase(it,a.end());

    vector<int> mod0, mod1, mod2;
    for (int x : a) {
        if (x % 3 == 0) mod0.push_back(x);
        else if (x % 3 == 1) mod1.push_back(x);
        else mod2.push_back(x);
    }

    sort(mod0.begin(), mod0.end());
    sort(mod1.rbegin(), mod1.rend());//по спаданню
    sort(mod2.begin(), mod2.end());

    a.clear();
    a.insert(a.end(), mod0.begin(), mod0.end());
    a.insert(a.end(), mod1.begin(), mod1.end());
    a.insert(a.end(), mod2.begin(), mod2.end());

    cout<<a.size()<<endl;
   for(auto i:a) cout<<i<<" ";
}