#include <iostream>
using namespace std;

int main() {
    int m; int n;
    int res;
    cout << "Enter m and n: "<<endl;
    cin>>m>>n;
    res=--m-++n;
    cout<<"--m-++n = "<<res<<endl<<endl;
    
    cout<<"m*n<n++? ";
    if(m*n<n++){
        cout<<"true"<<endl;}
    else cout<<"false"<<endl;

    cout<<"n-->m++? "<<endl;
    if(n-->m++){
        cout<<"true"<<endl;}
    else cout<<"false"<<endl;
    return 0;
}