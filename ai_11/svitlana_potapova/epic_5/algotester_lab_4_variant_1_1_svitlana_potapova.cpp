#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void printRes(vector<int>& array){
    cout << array.size() << endl;
    for (int num : array){
        cout << num << " ";
    }
    cout << endl << endl;
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

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> N_minus_M;
    set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(N_minus_M));

    vector<int> M_minus_N;
    set_difference(arr2.begin(), arr2.end(), arr1.begin(), arr1.end(), back_inserter(M_minus_N));

    vector<int> intersection;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(intersection));

    vector<int> unionres;
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(unionres));

    vector<int> sym_diff;
    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(sym_diff));

    printRes(N_minus_M);
    printRes(M_minus_N);
    printRes(intersection);
    printRes(unionres);
    printRes(sym_diff);

    return 0;
}
