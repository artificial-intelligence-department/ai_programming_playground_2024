#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n], dp[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;  
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}

