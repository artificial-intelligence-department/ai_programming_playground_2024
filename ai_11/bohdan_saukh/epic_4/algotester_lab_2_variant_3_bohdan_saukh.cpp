#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int res1 = 0;
    int res2 = n - 1;
    int road[n];
    
    for (int i = 0; i < n; i++){
        cin >> road[i];
    }
    
    while (!(res1 >= (res2 - 1))){
        res1 = res1 + road[res1];
        res2 = res2 - road[res2];        
    }
    
    cout << res1 + 1 << " " << res2 + 1 << endl;
    
    if (res1 == res2){
        cout << "Collision";
    }
    
    if (res1 == (res2 - 1)){
        cout << "Stopped";
    }
    
    if (res1 > res2){
        cout << "Miss";
    }
    
    return 0;
}
