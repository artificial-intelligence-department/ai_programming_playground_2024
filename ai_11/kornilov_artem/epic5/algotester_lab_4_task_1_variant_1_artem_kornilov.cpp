#include <iostream>
#include <algorithm>

using namespace std;

void print_array(int* arr, size_t size) {
    int* first = arr;
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    int sz1;
    int sz2;

    cin >> sz1;
    if (sz1 < 1 || sz1 > 100) {
        return 0;
    }

    int* arr1 = new int[sz1];
    for (int i = 0; i < sz1; i++) {
        cin >> arr1[i];
        if (arr1[i] < 1 || arr1[i] > 100) {
            delete[] arr1;
            return 0;
        }
    }

    cin >> sz2;
    if (sz2 < 1 || sz2 > 100) {
        return 0;
    }
    int* arr2 = new int[sz2];
    for (int i = 0; i < sz2; i++) {
        cin >> arr2[i];
        if (arr2[i] < 1 || arr2[i] > 100) {
            delete[] arr2;
            return 0;
        }
    }

    sort(arr1, arr1 + sz1);
    sort(arr2, arr2 + sz2);
    
    int* result = new int[sz1 + sz2];

    int* difference_end = set_difference(arr1, arr1 + sz1, arr2, arr2 + sz2, result);
    cout << difference_end - result << endl;
    print_array(result, difference_end - result);

    int* difference_end2 = set_difference(arr2, arr2 + sz2, arr1, arr1 + sz1, result);
    cout << difference_end2 - result << endl;
    print_array(result, difference_end2 - result);
    
    int* intersection_end = set_intersection(arr1, arr1 + sz1, arr2, arr2 + sz2, result);
    cout << intersection_end - result << endl;
    print_array(result, intersection_end - result);
    
    int* union_end = set_union(arr1, arr1 + sz1, arr2, arr2 + sz2, result);
    cout << union_end - result << endl;
    print_array(result, union_end - result);

    int* symmetric_difference_end = set_symmetric_difference(arr1, arr1 + sz1, arr2, arr2 + sz2, result);
    cout << symmetric_difference_end - result << endl;
    print_array(result, symmetric_difference_end - result);

    delete[] arr1;
    delete[] arr2;
    delete[] result;
    
    return 0;
}