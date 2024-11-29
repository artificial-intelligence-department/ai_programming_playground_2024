#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int index = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            arr[index++] = arr[i];
        }
    }
    return index;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> mod0, mod1, mod2;
    for (int i = 0; i < N; ++i) {
        if (arr[i] % 3 == 0) mod0.push_back(arr[i]);
        else if (arr[i] % 3 == 1) mod1.push_back(arr[i]);
        else mod2.push_back(arr[i]);
    }

    quickSort(mod0, 0, mod0.size() - 1);
    quickSort(mod1, 0, mod1.size() - 1);
    quickSort(mod2, 0, mod2.size() - 1);

    reverse(mod1.begin(), mod1.end());

    vector<int> result = mod0;
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    int n = removeDuplicates(result);
    
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
