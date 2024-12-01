#include <iostream>
#include <vector>

using namespace std;
// Власна реалізація
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quick_sort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);

        quick_sort(vec, low, pi - 1); 
        quick_sort(vec, pi + 1, high); 
    }
}

void remove_duplicates(vector<int>& vec) {
    int n = vec.size();
    if (n == 0) return;

    int index = 0; 
    for (int i = 1; i < n; i++) {
        if (vec[i] != vec[index]) {
            index++;
            vec[index] = vec[i];
        }
    }
    vec.resize(index + 1); 
}

void rotate_vector(vector<int>& vec, int k) {
    int n = vec.size();
    k %= n; 

    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = vec[(i + k) % n];
    }
    vec = temp;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> vec (n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    quick_sort(vec, 0, vec.size() - 1);
    remove_duplicates(vec);

    if (!vec.empty()) { 
        rotate_vector(vec, k);
    }

    cout << vec.size() << endl;
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}