#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void deleteDuplicat(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());

    k = k % arr.size();
    rotate(arr.begin(), arr.begin() + k, arr.end());

    cout << arr.size() << '\n';
    for (const int& num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    deleteDuplicat(arr, k);
    return 0;
}
