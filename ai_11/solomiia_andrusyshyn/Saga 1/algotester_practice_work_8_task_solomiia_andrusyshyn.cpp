#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, 1); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int lis_length = *max_element(dp.begin(), dp.end());

    cout << lis_length << endl;

    return 0;
}

