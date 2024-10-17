#include <iostream>
using namespace std;
int main() {
    int n, k, s, m;
    s = 0;
    m = 0;
    cin >> n >> k;
    int zubu[n];
    for (int i = 0; i < n; i++){
        cin >> zubu[i];
        if (zubu[i] >= k){
            s++;
        }
        else{
            if (s > m){
                m = s;
            }
            s = 0;
        }
    }
    if (s > m){
        cout << s;
    }
    else{
        cout << m;
    }
    return 0;
}