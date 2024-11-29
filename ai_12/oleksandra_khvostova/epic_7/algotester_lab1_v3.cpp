#include <iostream>
using namespace std;

int main(){
    long long cub[5];
    bool win=false;
    for(int i=0; i<5; i++){
        cin>>cub[i];
    }
    for(int i=0; i<4; i++){
        if(cub[i]<=0||cub[i+1]<=0){cout<<"ERROR"; win=false; break;}
        if(cub[i+1]>cub[i]){cout<<"LOSS"; win=false; break;}
        if(cub[i+1]<=cub[i]){win = true;} 
    }
    if(win){
        cout<<"WIN";
    }
    return 0;
}