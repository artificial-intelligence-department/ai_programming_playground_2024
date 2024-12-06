#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, bool ascending) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && arr[j] > key) || (!ascending && arr[j] < key))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void removeDuplicates(vector<int>& arr) {
    vector<int> uniqueArr;
    for (int x : arr) {
        if (uniqueArr.empty() || uniqueArr.back() != x) {
            uniqueArr.push_back(x);
        }
    }
    arr = uniqueArr;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> mod0, mod1, mod2;
    for (int x : arr) {
        if (x % 3 == 0)
            mod0.push_back(x);
        else if (x % 3 == 1)
            mod1.push_back(x);
        else
            mod2.push_back(x);
    }

    insertionSort(mod0, true);
    insertionSort(mod1, false);
    insertionSort(mod2, true);

    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    removeDuplicates(result);

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
