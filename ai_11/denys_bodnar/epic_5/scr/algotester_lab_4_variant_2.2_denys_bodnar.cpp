#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void delDuplicat(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    vector<int> Arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (find(Arr.begin(), Arr.end(), arr[i]) == Arr.end()) {
            Arr.push_back(arr[i]);
        }
    }

    k = k % Arr.size();
    rotate(Arr.begin(), Arr.begin() + k, Arr.end());

    cout << Arr.size() << '\n';
    for (const int& num : Arr) {
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

    delDuplicat(arr, k);
    return 0;
}
