#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    vector<int> arr;
    cin >> N >> K;
    if (N < 1 || N > 1000 || K < 1 || K > 1000) return 0;
    for (int i = 0; i < N; i++) {
        int el;
        cin >> el;
        if (el < 0 || el > 100) return 0;
        arr.push_back(el);
    }
    sort(arr.begin(), arr.end());
    vector<int> deleted;
    for (int j = 0; j < N; j++) {
        if ( arr[j]!=arr[j-1] || j == 0) {
            deleted.push_back(arr[j]);
        }
        
    }
    N = deleted.size();
    K %= N;
    for (int i = 0; i < K; ++i) {
        int first = deleted[0];
        for (int j = 0; j < N; ++j) {
            deleted[j] = deleted[j+1];
        }
        deleted[N-1] = first;
    }
    cout << N << endl;
    for (int s = 0; s < N; s++) {
        cout << deleted[s] << " ";
    }
    return 0;
} 