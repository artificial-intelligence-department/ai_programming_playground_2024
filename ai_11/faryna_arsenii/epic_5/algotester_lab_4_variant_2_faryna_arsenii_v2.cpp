#include <iostream>
#include <vector>

using namespace std;  

void quick_sort(vector<int>& arr, int first, int last){
    int middle = arr[(first + last) / 2];
    int i = first;
    int j = last;
    do{
        while (arr[j] > middle){
            j--;
        }
        while (arr[i] < middle){
            i++;
        }
        if (i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > first){
        quick_sort(arr, first, j);
    }
    if (i < last){
        quick_sort(arr, i, last);
    }
}

vector<int> remove_duplicate(const vector<int>& arr){
    vector<int> unique_arr;
    int n = arr.size();
    for (int i = 0; i < n; i++){
        if (i == 0 || arr[i] != arr[i - 1]){
            unique_arr.push_back(arr[i]);
        }
    }
    return unique_arr;
}

void rotate_arr(vector<int>& arr, int K) {  
    int n = arr.size();
    K = K % n;

    vector<int> rotated_arr(n);
    for (int i = 0; i < n; i++) {
        rotated_arr[i] = arr[(i + K) % n];  
    }
    arr = rotated_arr;  
}

int main (){
    int N, K;
    cin >> N >> K;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    quick_sort(arr, 0, arr.size() - 1);

    vector<int> unique_arr = remove_duplicate(arr);

    rotate_arr(unique_arr, K);
    
    cout << unique_arr.size() << endl;

    for (int i = 0; i < unique_arr.size(); i++){
        cout << unique_arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}