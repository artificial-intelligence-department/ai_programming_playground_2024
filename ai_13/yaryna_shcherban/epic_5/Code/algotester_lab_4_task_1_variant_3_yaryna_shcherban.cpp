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

    auto mod0_end = partition(arr.begin(), arr.end(), [](int x) { return x % 3 == 0; });
    auto mod1_end = partition(mod0_end, arr.end(), [](int x) { return x % 3 == 1; });

    sort(arr.begin(), mod0_end);
    sort(mod0_end, mod1_end, greater<int>());
    sort(mod1_end, arr.end());

    auto unique_end = unique(arr.begin(), arr.end());
    arr.erase(unique_end, arr.end());

    cout << arr.size() << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
