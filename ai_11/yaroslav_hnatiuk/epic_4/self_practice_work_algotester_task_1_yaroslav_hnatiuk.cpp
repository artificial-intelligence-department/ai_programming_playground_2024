#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1;      
    }

    sort(arr.begin(), arr.end());

    for (auto i : arr) {
        cout << i.second << " ";
    }

    return 0;
}

