#include <iostream>
#include <string>
using namespace std;


int main(){

int k,n;
cin >>k;
string toil;
cin >> toil;
n = 0;

for(int i = 0;i<toil.size();i++){
    if(toil[i] == 'T'){
        if(toil[i+1] == 'O'){
            if(toil[i+2] == 'I'){
                if(toil[i+3] == 'L'){
                    if(toil[i+4] == 'E'){
                        if(toil[i+5] == 'T'){
                            ++n;
                            i +=5;
                        }
                    }
                }
            }
        }
    }
    
}

if(n>=k){
    cout <<"YES";
}
else{
    cout <<"NO";
}

    return 0;
}