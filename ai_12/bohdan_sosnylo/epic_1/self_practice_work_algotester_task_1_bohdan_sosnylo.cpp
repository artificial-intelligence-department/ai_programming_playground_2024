#include <iostream>
using namespace std;

int main()
{
   unsigned int n,t = 0;
   cin >> n;
  
   if(n/500>=1){
       t +=n/500;
       n-=500*(n/500);
   }
   if(n/200>=1){

       t +=n/200;
       n-=200*(n/200);
   }
   if(n/100>=1){
       t +=n/100;
       n-=100*(n/100);
   }
   if(n/50>=1){
       t +=n/50;
       n-=50*(n/50);
   }
   if(n/20>=1){
       t +=n/20;
       n-=20*(n/20);
   }
   if(n/10>=1){
       t +=n/10;
       n-=10*(n/10);
   }
   if(n/5>=1){
       t +=n/5;
       n-=5*(n/5);
   }
   if(n/2>=1){
       t +=n/2;
       n-=2*(n/2);
   }
   if(n/1>=1){
       t +=n/1;
       n-=1*(n/1);
   }
   
   
   cout << t;



    return 0;
}