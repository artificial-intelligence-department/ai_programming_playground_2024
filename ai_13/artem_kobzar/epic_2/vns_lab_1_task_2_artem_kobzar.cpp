#include <iostream>

using namespace std;

int main()
{
    long n;
    long m;
    cin>>n>>m;
    int a =n++-m;          //a gets n-m then n increments
    bool b = m-->n;        //b true(1) if m>n and then m gets decremanted
    bool c = n-->m;        //c true(1) if n>m and then n gets decremanted
    cout<<n<<" "<<m<<endl; //n will be the same because we got it incremented and then decremented
    cout<<"a equals: "<<a<<" b equals: "<<b<<" c equals: "<<c;
return 0;
}