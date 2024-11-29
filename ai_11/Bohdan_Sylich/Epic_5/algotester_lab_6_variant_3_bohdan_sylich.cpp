#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), [](int a, int b) {
        int modA = a % 3, modB = b % 3;
        if (modA != modB) return modA < modB;
        if (modA == 1) return a > b;
        return a < b;
    });
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    cout << arr.size() << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

