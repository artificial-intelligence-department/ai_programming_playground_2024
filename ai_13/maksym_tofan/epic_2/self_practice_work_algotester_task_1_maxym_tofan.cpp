#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    if (n == 1) {
        cout << 0;
    } else {
        int diff1 = arr[n - 1] - arr[1];
        int diff2 = arr[n - 2] - arr[0];
        cout << min(diff1, diff2);
    }

    return 0;
}
