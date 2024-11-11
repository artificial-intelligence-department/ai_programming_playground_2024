#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

vector<int> removeDuplicatesAfterSorting(const vector<int>& arr) {
    vector<int> uniqueArr;
    for (size_t i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            uniqueArr.push_back(arr[i]);
        }
    }
    return uniqueArr;
}


int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    quickSort(vec, 0, N - 1);

    vec = removeDuplicatesAfterSorting(vec);


    vector<int> mod0, mod1, mod2;
    for (int num : vec) {
        if (num % 3 == 0) {
            mod0.push_back(num);
        } else if (num % 3 == 1) {
            mod1.push_back(num);
        } else {
            mod2.push_back(num);
        }
    }

    //mod0 and mod1 are already sorted
    for (size_t i = 0; i < mod1.size() / 2; i++) {
        swap(mod1[i], mod1[mod1.size() - 1 - i]);
    }


    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    int len = result.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        if(i != len -1){
            cout << result[i] << " ";
        }else{
            cout << result[i];
        }
    }
}