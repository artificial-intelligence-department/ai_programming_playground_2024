#include <iostream>

using namespace std;

int main(){
    long r;
    bool w = 1;
    bool er = 0;  
    for(short int i = 0; i < 5; i++){
        long x;
        cin>>x;
        if (x <= 0 && w == 1){
            er = 1;
            w = 0;
        }        
        if (i > 0 && er == 0 && x > r){
            w = 0;
        }
        r = x;
    }
    if (er == 1){
        cout<<"ERROR";
    }else if (w == 1){
        cout<<"WIN";
    }else {
        cout<<"LOSS";
    }
    return 0;
}
