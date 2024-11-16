#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
bool customComparator(int a, int b) {
    if (a % 3 != b % 3)
        return a % 3 < b % 3;
    if (a % 3 == 0)
        return a < b;
    if (a % 3 == 1)
        return a > b;
    return a < b;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), customComparator);

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    cout << arr.size() << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
