#include <iostream>

using namespace std;

int main(){
    long long int a, temp, k;
    bool error = false;
    bool loss = false;
    for(int i = 0; i<5;i++){
        cin>>a;
        temp=a;
        if(temp<=0){
            error = true;
            break;
        }else if(k<temp){
            loss = true;
            break;
        }
        k=temp;
    }
    if(error){
        cout<<"ERROR"<<endl;
    }
    else if(loss){
        cout<<"LOSS"<<endl;
    }else{
        cout<<"WIN"<<endl;
    }
}
    
    


