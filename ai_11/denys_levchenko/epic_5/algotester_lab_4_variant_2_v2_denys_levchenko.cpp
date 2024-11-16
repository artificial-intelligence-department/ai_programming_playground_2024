#include <iostream>
#include <vector>

using namespace std;
void sortArray(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void removeDuplicates(vector<int>& arr) {
    int index = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[index]) {
            arr[++index] = arr[i];
        }
    }
    arr.resize(index + 1);
}

void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    vector<int> temp(n);
    
    for (int i = 0; i < n; ++i) {
        temp[i] = arr[(i + k) % n];
    }
    
    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    sortArray(a);
    removeDuplicates(a);

    N = a.size();
    cout << N << endl;

    rotateArray(a, K);
    
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
