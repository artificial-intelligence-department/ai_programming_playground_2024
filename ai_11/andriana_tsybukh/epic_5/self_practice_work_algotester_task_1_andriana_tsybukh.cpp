#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void print_set(vector<int>& array){
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

    // N-M
    vector<int> diff1;
    set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(diff1));

    // M-N
    vector<int> diff2;
    set_difference(arr2.begin(), arr2.end(), arr1.begin(), arr1.end(), back_inserter(diff2));

    // перетин
    vector<int> intersection;
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(intersection));

    // oб'єднання
    vector<int> union_set;
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(union_set));

    // cиметрична різниця
    vector<int> symmetric_diff;
    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(symmetric_diff));

    print_set(diff1);
    print_set(diff2);
    print_set(intersection);
    print_set(union_set);
    print_set(symmetric_diff);

    return 0;
}