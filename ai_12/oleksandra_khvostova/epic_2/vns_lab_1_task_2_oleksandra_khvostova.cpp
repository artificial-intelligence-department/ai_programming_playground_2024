#include <iostream>
using namespace std;

int main() {
    int m; int n;
    int res;
    cout << "Enter m and: "<<endl;
    cin>>m>>n;
    res=--m-++n;
    cout<<res<<endl;
    if(m*n<n++){
        cout<<"true"<<endl;
    };
    if(n-->m++){
        cout<<"false"<<endl;
    }
    return 0;
}