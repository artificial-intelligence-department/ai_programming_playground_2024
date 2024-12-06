#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int find_median(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 1) {
        return arr[n / 2];  
    } else {
        return arr[n / 2 - 1];  
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int A = find_median(a);
    int B = find_median(b);
    int C = find_median(c);

    long long total_disbelief = 0;
    for (int i = 0; i < n; ++i) {
        total_disbelief += abs(A - a[i]) + abs(B - b[i]) + abs(C - c[i]);
    }

    cout << total_disbelief << endl;

    return 0;
}
