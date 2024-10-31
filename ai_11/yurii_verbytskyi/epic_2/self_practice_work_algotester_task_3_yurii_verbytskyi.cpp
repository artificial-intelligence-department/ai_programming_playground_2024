#include <iostream>

using namespace std;

int main(){

    long long a[5];

    for(int i = 0; i < 5; i++){
       cin >> a[i];
    }
 
   for(int i = 0; i < 5; i++){
       if(a[i] < 1){
        cout << "ERROR";
        return 0;
       } 
    }

    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 5; j++){
            if(a[i] < a[j]){
                cout << "LOSS";
                return 0;
            }
        }
        
    }

    cout << "WIN";
    
    return 0;
}
