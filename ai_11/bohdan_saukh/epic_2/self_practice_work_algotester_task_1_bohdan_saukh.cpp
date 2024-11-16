#include <iostream>

using namespace std;

int main(){

    long H,M,HDam,MDam,HDam1,MDam1,HDam2,MDam2;

    cin>>H>>M;
    cin>>HDam>>MDam;
    cin>>HDam1>>MDam1;
    cin>>HDam2>>MDam2;

    if((HDam != 0 && MDam != 0) || (HDam1 != 0 && MDam1 != 0) || (HDam2 != 0 && MDam2 != 0)){
        cout<<"NO";
    }else{
        if((H-HDam-HDam1-HDam2) > 0 && (M-MDam-MDam1-MDam2) > 0){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }
}
