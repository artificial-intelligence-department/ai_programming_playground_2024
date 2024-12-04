#include <iostream>
#include <vector>

using namespace std;

void print_reverse_order(vector<int>& arr){
    for (int i = arr.size() - 1; i >= 0; i--){
        cout << arr[i] << " ";
    }
}

void merge(vector<int>& arr, int left, int mid, int right){
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printVector(vector<int>& arr){
    
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

vector<int> removeDuplicates(const vector<int>& arr){
    vector<int> resault;

    for (int i = 0; i < arr.size(); i++){
        bool is_duplicate = false;
        
        for (int j = 0; j < resault.size(); j++){
            if (arr[i] == resault[j]){
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate){
            resault.push_back(arr[i]);
        }
    }
    return resault;
}

int main(){
    
    int n;
    cin >> n;
    
    int mas[n];
    vector<int> mas_0;
    vector<int> mas_1;
    vector<int> mas_2;

    for (int i = 0; i < n; i++){
        cin >> mas[i];
        if (mas[i] % 3 == 0){
            mas_0.push_back(mas[i]);
        }
        if (mas[i] % 3 == 1){
            mas_1.push_back(mas[i]);
        }
        if (mas[i] % 3 == 2){
            mas_2.push_back(mas[i]);
        }
    }
    
    mergeSort(mas_0, 0, mas_0.size() - 1);
    mergeSort(mas_1, 0, mas_1.size() - 1);
    mergeSort(mas_2, 0, mas_2.size() - 1);
    
    mas_0 = removeDuplicates(mas_0);
    mas_1 = removeDuplicates(mas_1);
    mas_2 = removeDuplicates(mas_2);
    
    cout << mas_0.size() + mas_1.size() + mas_2.size() << endl;
    
    printVector(mas_0);
    print_reverse_order(mas_1);
    printVector(mas_2);
    
    return 0;
}    
