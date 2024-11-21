#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int Median(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 1) {
        return arr[n/2];
    } else {
        return (arr[n/2 - 1] + arr[n / 2]) / 2;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> borsch(n), potato(n), salad(n);

    for (int i = 0; i < n; i++) {
        cin >> borsch[i] >> potato[i] >> salad[i];
    }
    int A = Median(borsch);
    int B = Median(potato);
    int C = Median(salad);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(borsch[i] - A);
        ans += abs(potato[i] - B);
        ans += abs(salad[i] - C);
    }

    cout << ans << endl;
    return 0;
}
