#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void Print(const vector<int>& result) {
    cout << result.size() << endl;
    for(int elm : result) {
        cout << elm << " ";
    }
    cout << endl << endl;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> arr1(N);
    for(int i = 0; i < N; i++) {
       cin >> arr1[i];
    }
    
    cin >> M;
    vector<int> arr2(M);
    for(int i = 0; i < M; i++) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> result;
    
    set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(result));
    Print(result);
    result.clear();

    set_difference(arr2.begin(), arr2.end(), arr1.begin(), arr1.end(), back_inserter(result));
    Print(result);
    result.clear();

    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(result));
    Print(result);
    result.clear();

    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(result));
    Print(result);
    result.clear();

    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(result));
    Print(result);
    result.clear();

    return 0;
}
