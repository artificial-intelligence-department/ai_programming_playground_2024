#include <iostream>
#include <vector>
using namespace std;

void SplitByModul(const vector<int>& arr, vector<int>& mod0, vector<int>& mod1, vector<int>& mod2) {
    for (int num : arr) {
        if (num % 3 == 0) mod0.push_back(num);
        else if (num % 3 == 1) mod1.push_back(num);
        else mod2.push_back(num);
    }
}

void quickSort(vector<int>& arr, int left, int right, bool ascending) {
    if (left >= right) return;

    int mid = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (ascending ? arr[i] < mid : arr[i] > mid) i++;
        while (ascending ? arr[j] > mid : arr[j] < mid) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j, ascending);
    if (i < right) quickSort(arr, i, right, ascending);
}

vector<int> removeDuplicates(const vector<int>& arr) {
    vector<int> result;
    for (int num : arr) {
        if (result.empty() || result.back() != num) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    vector<int> mod0, mod1, mod2;
    SplitByModul(arr, mod0, mod1, mod2);

    quickSort(mod0, 0, mod0.size() - 1, true);  // за зростанням
    quickSort(mod1, 0, mod1.size() - 1, false); // за спаданням
    quickSort(mod2, 0, mod2.size() - 1, true);  // за зростанням


    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());
    result = removeDuplicates(result);
    
    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
