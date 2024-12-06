#include <iostream>
using namespace std;

int main() {
    int n, k, maxi = 0, now = 0;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        if (ai >= k) {
            now++;
            maxi = max(maxi, now);
        } else {
            now = 0;
        }
    }
    
    cout << maxi << endl;
    
    return 0;
}
