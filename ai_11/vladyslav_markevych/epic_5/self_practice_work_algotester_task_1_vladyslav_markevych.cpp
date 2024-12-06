#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double l,w,u,d;
    cin>>l>>w>>u>>d;

    if(u+d >=l && w>=l){
        cout<<"Three times Sex on the Beach, please!"<<endl;
    }else{
        cout<<"Forget about the cocktails, man!"<<endl;
    }

    return 0;
}