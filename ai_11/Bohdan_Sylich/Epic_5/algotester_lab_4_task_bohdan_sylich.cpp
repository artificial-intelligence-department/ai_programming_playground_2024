#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> difference(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    for (int num : a) {
        if (!binary_search(b.begin(), b.end(), num)) {
            result.push_back(num);
        }
    }
    return result;
}

vector<int> intersection(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    for (int num : a) {
        if (binary_search(b.begin(), b.end(), num)) {
            result.push_back(num);
        }
    }
    return result;
}

vector<int> unionSet(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i++]);
        } else if (b[j] < a[i]) {
            result.push_back(b[j++]);
        } else {
            result.push_back(a[i]);
            ++i, ++j;
        }
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}

vector<int> symmetricDifference(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i++]);
        } else if (b[j] < a[i]) {
            result.push_back(b[j++]);
        } else {
            ++i, ++j;
        }
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> arr1(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr1[i];
    }

    cin >> M;
    vector<int> arr2(M);
    for (int i = 0; i < M; ++i) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> res;

    res = difference(arr1, arr2);
    cout << res.size() << endl;
    for (int num : res) cout << num << " ";
    cout << endl;

    res = difference(arr2, arr1);
    cout << res.size() << endl;
    for (int num : res) cout << num << " ";
    cout << endl;

    res = intersection(arr1, arr2);
    cout << res.size() << endl;
    for (int num : res) cout << num << " ";
    cout << endl;

    res = unionSet(arr1, arr2);
    cout << res.size() << endl;
    for (int num : res) cout << num << " ";
    cout << endl;

    res = symmetricDifference(arr1, arr2);
    cout << res.size() << endl;
    for (int num : res) cout << num << " ";
    cout << endl;

    return 0;
}
