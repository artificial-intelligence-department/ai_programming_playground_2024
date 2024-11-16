#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void operations_with_sets(){
    int N, M;

    cin >> N;
    vector<int> arr1(N);
    for (int i = 0; i < N; i++){
        cin >> arr1[i];
    }    

    cin >> M;
    vector<int> arr2(M);
    for (int i = 0; i < M; i++){
        cin >> arr2[i];
    }    

    vector<int> result1;
    vector<int> result2;
    vector<int> intersection;
    vector<int> union_result;
    vector<int> sym_diff_result;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(result1));
    set_difference(arr2.begin(), arr2.end(), arr1.begin(), arr1.end(), back_inserter(result2));
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(intersection));
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(union_result));
    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(sym_diff_result));

    //result for (N - M)
    cout << result1.size() << endl;
    for (int num1 : result1){
        cout << num1 << " ";
    }
    
    cout << endl;
    
    cout << result2.size() << endl;
    
    //result for (M - N)
    
    for (int num2 : result2){
        cout << num2 << " ";
    }
    cout << endl;

    //result for intersection
    
    cout << intersection.size() << endl;
    for (int num3 : intersection){
        cout << num3 << " ";
    }
    cout << endl;

    //result for union

    cout << union_result.size() << endl;
    for (int num4 : union_result){
        cout << num4 << " ";
    }
    cout << endl;

    //result for symetric difference

    cout << sym_diff_result.size() << endl;
    for (int num5 : sym_diff_result){
        cout << num5 << " ";
    }
    cout << endl;
    
}

int main (){

    operations_with_sets();

    return 0;
}