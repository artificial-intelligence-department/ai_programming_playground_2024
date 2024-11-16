#include <iostream>
#include <vector>
using namespace std;

void divine(vector<int> &arr, int first, int last) {
    if(first != last && first < last) {
        int pivot = arr[last];


        int idx = first;    //потім туди нашу опору запихати будемо
        for(int i = first; i < last; i++) {
            if(arr[i] < pivot) {
                swap(arr[i], arr[idx]);
                idx++;
            }
        }
        swap(arr[last], arr[idx]);
        divine(arr, first, idx - 1);
        divine(arr, idx + 1, last);     //не включаємо попередню опору
    }
}

int main() {

    int arr_size;
    cout << "Input size of array: ";
    cin >> arr_size;
    vector<int> arr(arr_size);
    for(int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
    int size = arr.size() - 1; 

    divine(arr, 0, size);
    for(int i : arr) {
        cout << i << " ";
    }


    return 0;
}