#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int s = 0;

  
    for (int i = 0; i < n - 1; i++) {
        if (p[i] + 1 != p[i + 1]) {  
            s++;
        }
    }
    s++;  

   
    if (s <= k) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}
