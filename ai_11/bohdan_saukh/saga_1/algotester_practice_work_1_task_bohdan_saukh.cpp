#include <iostream>

using namespace std;

int main(){
    long long res = 0;
    long long n;
    cin >> n;
    long long mas[n];
    for (int i = 0; i < n; i++){
        cin >> mas[i];   
    }    
    for (int i = 0; i < n; i++){
        if(mas[i] > 1){
            res += (mas[i] - 1);
        }
    }   
    cout << res;
}