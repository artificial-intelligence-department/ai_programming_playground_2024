#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"n, m= ";
    cin>>n>>m;
    cout<<"n, m = "<<n<<", "<<m<<endl;
    cout<<"n++*m= "<<n++*m<<endl;
    cout<<"n, m = "<<n<<", "<<m<<endl;
    cout<<"n++<m= "<<(n++<m)<<endl;
    cout<<"n, m = "<<n<<", "<<m<<endl;
    cout<<"m-->m= "<<(m-->m)<<endl;
    cout<<"n, m = "<<n<<", "<<m<<endl;
}