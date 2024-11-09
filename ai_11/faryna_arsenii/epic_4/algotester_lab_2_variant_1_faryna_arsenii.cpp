#include <iostream>
#include <climits>

using namespace std;

int find_min_tiredness(int arr[], int N) {
    if (N <= 1) {
        return 0;
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    for (int i = 0; i < N; i++){
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    int initial_tiredness = max_val - min_val;

    int min_tiredness = initial_tiredness;
    for (int i = 0; i < N; i++) {
        if (arr[i] == min_val || arr[i] == max_val) {
            int new_min = INT_MAX;
            int new_max = INT_MIN;
            for (int k = 0; k < N; k++){
                if (k != i){
                    new_min = min(new_min, arr[k]);
                    new_max = max(new_max, arr[k]);
                }
            }
            min_tiredness = min(min_tiredness, new_max - new_min);
        }
    }
    return min_tiredness;
}

int main() {
    int N;
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

    }

    int result = find_min_tiredness(arr, N);
    cout << result << endl;

    delete[] arr;
    return 0;
}