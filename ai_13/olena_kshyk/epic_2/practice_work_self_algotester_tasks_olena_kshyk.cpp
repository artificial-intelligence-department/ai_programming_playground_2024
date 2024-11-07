#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int max = 0;
    int current = 0;

    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        if (a >= k){
            current++;
        } else {
            current = 0;
        }
        max = (max > current)? max : current;
    }
    cout << max;
    return 0;
}