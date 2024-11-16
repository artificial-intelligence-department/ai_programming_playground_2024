#include<bits/stdc++.h>
//4.2
using namespace std;

int main(){
   int n,k;
   cin>>n>>k;
   vector<int>a(n),b,c;
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   sort(a.begin(), a.end());
   b.push_back(a[0]);
   for(int i=1;i<n;i++){
       if(a[i]!=a[i-1]) b.push_back(a[i]);
   }
   n=b.size();
   for(int i=0;i<n;i++){
       c.push_back(b[ (i+k)%n ]);
   }
   cout<<n<<endl;
   for(auto i:c)
       cout<<i<<" ";
}