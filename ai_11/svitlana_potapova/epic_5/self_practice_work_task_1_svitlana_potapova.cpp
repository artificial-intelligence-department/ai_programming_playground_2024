#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector<int>& array) {
    for (int i = 0; i < array.size(); ++i) {
        for (int j = i + 1; j < array.size(); ++j) {
            if (array[i] == array[j]) {
                array.erase(array.begin() + j);
                --j;
            }
        }
    }
}

void bubbleSort(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

void rotateArray(vector<int>& arr, int K) {
    K = K % arr.size();
    vector<int> temp1(arr.begin(), arr.begin() + K);
    vector<int> temp2(arr.begin() + K, arr.end());
    arr = temp2;
    arr.insert(arr.end(), temp1.begin(), temp1.end());
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    removeDuplicates(arr);
    bubbleSort(arr);
    rotateArray(arr, K);

    cout << arr.size() << endl;
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}






