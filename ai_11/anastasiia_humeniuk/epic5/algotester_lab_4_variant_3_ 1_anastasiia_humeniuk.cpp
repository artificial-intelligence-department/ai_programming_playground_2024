#include <iostream>

using namespace std;

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int middle = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < middle) 
        i++;
        while (arr[j] > middle) 
        j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

void insert_unique(int source[], int &source_size, int result_array[], int &result_size) {
    for (int i = 0; i < source_size; ++i) {
        bool is_duplicate = false;
        for (int j = 0; j < result_size; ++j) {
            if (result_array[j] == source[i]) {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate) {
            result_array[result_size++] = source[i];
        }
    }
}

int main() {
    int N;
    cin >> N;
    int numbers[1000];
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int remainder0[1000], remainder1[1000], remainder2[1000];
    int size0 = 0, size1 = 0, size2 = 0;

    //три масиви за остачами
    for (int i = 0; i < N; ++i) {
        if (numbers[i] % 3 == 0) {
            remainder0[size0++] = numbers[i];
        } else if (numbers[i] % 3 == 1) {
            remainder1[size1++] = numbers[i];
        } else {
            remainder2[size2++] = numbers[i];
        }
    }

    // Сортування
    quick_sort(remainder0, 0, size0 - 1);  
    quick_sort(remainder1, 0, size1 - 1); 
    quick_sort(remainder2, 0, size2 - 1);

    //масив з остачею 1 по спаданню
    for (int i = 0; i < size1 / 2; ++i) {
        swap(remainder1[i], remainder1[size1 - 1 - i]);
    }

    // об'єдання масиву
    int result[1000];
    int result_size = 0;

    insert_unique(remainder0, size0, result, result_size);
    insert_unique(remainder1, size1, result, result_size);
    insert_unique(remainder2, size2, result, result_size);

    cout << result_size << endl;
    for (int i = 0; i < result_size; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
