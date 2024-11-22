#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printRes(vector<int>& array){
    sort(array.begin(), array.end());
    cout << array.size() << endl;
    for (int num : array){
        cout << num << " ";
    }
    cout << endl << endl;
}

bool found(const vector<int>& vec, int num){
    for (int n : vec) {
        if (n == num) {
            return true;
        }
    }
    return false;
}

int main(){
    int N, M;
    cin >> N;
    vector<int> arr1(N);

    for(int i=0; i<N; i++){
        cin >> arr1[i];
    }

    cin >> M;
    vector<int> arr2(M);

    for(int i=0; i<M; i++){
        cin >> arr2[i];
    }

    // N - M
    vector<int> N_minus_M;
    for (int num : arr1) {
        if (!found(arr2, num)) { 
            N_minus_M.push_back(num);
        }
    }

    //M - N
    vector<int> M_minus_N;
    for (int num : arr2) {
        if (!found(arr1, num)) { 
            M_minus_N.push_back(num);
        }
    }

    // Перетин
    vector<int> intersection;
    for (int num : arr1) {
        if (found(arr2, num)) { 
            intersection.push_back(num);
        }
    }

    // Об'єднання
    vector<int> union_set;
    for (int num : arr1) {
        if (!found(union_set, num)) {
            union_set.push_back(num);
        }
    }

    for (int num : arr2) {
        if (!found(union_set, num)) {
            union_set.push_back(num);
        }
    }

    // Cиметрична різниця
    vector<int> sym_diff;
    for (int num : arr1) {
        if (!found(arr2, num)) { 
            sym_diff.push_back(num);
        }
    }

    for (int num : arr2) {
        if (!found(arr1, num)) { 
            sym_diff.push_back(num);
        }
    }
    printRes(N_minus_M);
    printRes(M_minus_N);
    printRes(intersection);
    printRes(union_set);
    printRes(sym_diff);
    return 0;
}


