#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> difference_arr1_arr2(vector<int> arr1, vector<int> arr2){
    vector<int> result;
    for (int a : arr1){
        bool found = false;
        for (int b : arr2){
            if (a == b){
                found = true;
                break;
            }
        }
    if (!found){
        result.push_back(a);
        }
    }
    return result;
}

vector<int> difference_arr2_arr1(vector<int> arr2, vector<int> arr1){
    vector<int> result;
    for (int b : arr2){
        bool found = false;
        for (int a : arr1){
            if (b == a){
                found = true;
                break;
            }
        }
    if (!found){
        result.push_back(b);
        }
    }
    return result;
}

vector<int> intersection(vector<int> arr1, vector<int> arr2){
    vector<int> result;
    for(int a : arr1){
        for (int b : arr2){
            if (a == b){
                result.push_back(a);
                break;
            }
        }
    }
    return result;
}

vector<int> union_array(vector<int> arr1, vector<int> arr2){
    vector<int> result = arr1;
    for(int b : arr2){
        bool found = false;
        for (int a : arr1){
            if (a == b){
                found = true;
                break;
            }
        }
        if (!found){
            result.push_back(b);
        }
    }
    return result;
}

vector<int> symetric_difference(vector<int> arr1, vector<int> arr2){
    vector<int> result;
    for (int a : arr1){
        bool found = false;
        for (int b : arr2){
            if (a == b){
                found = true;
                break;
            }
        }
        if (!found){
            result.push_back(a);
        }
    }

    for (int b : arr2){
        bool found = false;
        for (int a : arr1){
            if (a == b){
                found = true;
                break;
            }
        }
        if (!found){
            result.push_back(b);
        }
    }
    return result;
}

int main (){

    int N, M;
    
    cin >> N;
    vector<int> arr1(N);
    for(int i = 0; i < N; i++){
        cin >> arr1[i];
    }
    
    cin >> M;
    vector<int> arr2(M);
    for(int i = 0; i < M; i++){
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> diff1 = difference_arr1_arr2(arr1, arr2);
    vector<int> diff2 = difference_arr2_arr1(arr2, arr1);
    vector<int> intersection1 = intersection(arr1, arr2);
    vector<int> union_set = union_array(arr1, arr2);
    vector<int> sym_diff = symetric_difference(arr1, arr2);

    cout << diff1.size() << endl;
    for (int num : diff1) {
        cout << num << " ";
    }
    cout << endl;

    cout << diff2.size() << endl;
    for (int num : diff2) {
        cout << num << " ";
    }
    cout << endl;

    cout << intersection1.size() << endl;
    for (int num : intersection1) {
        cout << num << " ";
    }
    cout << endl;

    cout << union_set.size() << endl;
    for (int num : union_set) {
        cout << num << " ";
    }
    cout << endl;

    cout << sym_diff.size() << endl;
    for (int num : sym_diff) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}