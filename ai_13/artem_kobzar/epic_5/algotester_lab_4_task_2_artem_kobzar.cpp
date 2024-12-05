#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K; 
    cin >> N >> K;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    auto last_unique = unique(arr.begin(), arr.end());
    arr.erase(last_unique, arr.end());

    int rotation_index = K % arr.size();
    rotate(arr.begin(), arr.begin() + rotation_index, arr.end());

    cout << arr.size() << "\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
