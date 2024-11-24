#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

vector<int> unique(vector<int>& arr) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        if (result.empty() || arr[i] != result.back()) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

vector<int> reverse(vector<int>& arr, int K) {
    int t = arr.size();
    K %= t; 
    vector<int> result(t);

    for (int i = 0; i < t; i++) {
        result[(i + t - K) % t] = arr[i];
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a);
    vector<int> filtered = unique(a);
    vector<int> reversed = reverse(filtered, K);

    cout << filtered.size() << endl;

    for (int i = 0; i < reversed.size(); i++) {
        cout << reversed[i] << " ";
    }
    cout << endl;

    return 0;
}
