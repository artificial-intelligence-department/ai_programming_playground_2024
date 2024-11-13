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
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    N = arr.size();
    K = K % N;
    rotate(arr.begin(), arr.begin() + K, arr.end());

    cout << N << endl;
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            cout << arr[i] << " ";
        } else {
            cout << arr[i];
        }
    }

    return 0;
}
