#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long b, s=0; 
    for (int i=0; i<n; i++){
     cin >> b; 
     if(b>0){
        s+=b-1;
     }

    }
    cout << s;
    return 0;
}