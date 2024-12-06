#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int low, int high) {

    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    int temp2 = vec[i + 1];
    vec[i + 1] = vec[high];
    vec[high] = temp2;
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {

    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void removeDuplicates(std::vector<int>& vec) {
    int size = vec.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (vec[i] == vec[j]) {
                for (int k = j; k < size - 1; k++) {
                    vec[k] = vec[k + 1];
                }
                size--;
                j--;
            }
        }
    }

    vec.resize(size);
}


int main(){
    int element = 0;    
    int N = 0;
    int K = 0;
    cin >> N >> K;

    vector<int> arr;

    for (int c = 0; c < N; c++) {
        cin >> element;
        arr.push_back(element);
    }

    removeDuplicates(arr);
    quickSort(arr, 0, arr.size() - 1);

    vector<int> temp(arr.begin(), arr.begin() + K);
    
    K %= N;

    for (int i = 0; i < arr.size() - K; i++) {
        arr[i] = arr[i + K];
    }

    for (int i = 0; i < K; i++) {
        arr[arr.size() - K + i] = temp[i];
    }

    int M = arr.size();
    cout << M << endl;
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}