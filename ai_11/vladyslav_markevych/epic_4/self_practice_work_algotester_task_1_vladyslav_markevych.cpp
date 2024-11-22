#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];  
    }

    int maxLength = 0;  
    int currentLength = 0;  

    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            currentLength++;  
        } else {
            maxLength = max(maxLength, currentLength);  
            currentLength = 0;  
        }
    }

    maxLength = max(maxLength, currentLength);

    cout << maxLength << endl; 

    return 0;
}
