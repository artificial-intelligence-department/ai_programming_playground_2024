#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
int c, k, l=1;
cout<<"Enter number: ";
cin>>c;
do{
k+=(c%2)*l;
c=c/2;
l=l*10;
}while (c!=0);
cout<<k<<endl;
}
