#include <iostream>

using namespace std;

int main(){
    double H = 0, M = 0;

    cin>>H >>M;
    for(int i=0; i < 3;i++){
        double hi = 0, mi = 0;
        cin>>hi >>mi;

    

    if(hi>0 && mi>0){
        cout<<"NO"<<endl;
        return 0;
    
    }

    if (hi>0){
        H -= hi;
    }

    else if (mi>0){
        M -= mi;
    }
    }

    if (H>0 && M>0){
        cout<<"YES"<<endl;
    } else  {
        cout<<"NO"<<endl;
    }

    return 0;
}
