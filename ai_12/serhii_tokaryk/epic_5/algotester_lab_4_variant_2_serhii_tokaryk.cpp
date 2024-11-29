#include <iostream>
#include <vector>

using namespace std;

vector<int> remove_duplicates(const vector<int>& arr) {
    vector<int> unique_arr;
    vector<bool> seen(101, false);

    for (int num : arr) {
        if (!seen[num]) {
            seen[num] = true;
            unique_arr.push_back(num);
        }
    }

    for (int i = 0; i < unique_arr.size(); i++) {
        for (int j = i + 1; j < unique_arr.size(); j++) {
            if (unique_arr[i] > unique_arr[j]) {
                swap(unique_arr[i], unique_arr[j]);
            }
        }
    }
    return unique_arr;
}

void rotate_array(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }
    arr = temp;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> unique_arr = remove_duplicates(a);

    int n = unique_arr.size();

    rotate_array(unique_arr, K);

    cout << n << endl;
    for (int x : unique_arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
