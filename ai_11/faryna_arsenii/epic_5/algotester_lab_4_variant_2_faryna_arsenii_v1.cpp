#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main (){

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());

    int n = arr.size();
    K = K % n;
    rotate(arr.begin(), arr.begin() + K, arr.end());

    cout << n << endl;

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}