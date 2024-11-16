#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void Show(const vector<int>& temp);

int main() {
    int N, K;
    cin >> N;
    if (N > 1000 || N < 1) return 1;
    cin >> K;
    if (K > 1000 || K < 1) return 1;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > 100 || arr[i] < 0) {
            return 1;
        }
    }

    set<int> uniqueSet(arr.begin(), arr.end());
    
    vector<int> temp(uniqueSet.begin(), uniqueSet.end());

    sort(temp.begin(), temp.end());
    K = K % temp.size();
    rotate(temp.begin(), temp.begin() + K, temp.end());

    Show(temp);

    return 0;
}

void Show(const vector<int>& temp) {
    cout << temp.size() << endl;
    for (int val : temp) {
        cout << val << " ";
    }
    cout << endl;
}
