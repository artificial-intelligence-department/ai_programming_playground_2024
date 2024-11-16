#include<bits/stdc++.h>
//4.2
using namespace std;

int main(){
   int n,k;
   cin>>n>>k;
   vector<int>a(n);
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   sort(a.begin(), a.end());
   auto it= unique(a.begin(), a.end());
   a.erase(it, a.end());

   n=a.size();
   k%=n;
    cout<<n<<endl;
   rotate(a.begin(),a.begin()+k, a.end());
   for(auto i:a){
       cout<<i<<" ";
   }

}

