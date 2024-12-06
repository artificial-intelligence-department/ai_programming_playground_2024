#include <stdio.h>
#include <iostream>

using namespace std;

void sort1(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort2(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    return j;
}

int main() {
    int N;
    scanf("%d", &N);

    int *array = new int[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int *remainder0 = new int[N];
    int *remainder1 = new int[N];
    int *remainder2 = new int[N];
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < N; i++) {
        if (array[i] % 3 == 0) {
            remainder0[count0++] = array[i];
        } else if (array[i] % 3 == 1) {
            remainder1[count1++] = array[i];
        } else {
            remainder2[count2++] = array[i];
        }
    }

   sort2(remainder0, count0); 
   sort1(remainder1, count1); 
   sort2(remainder2, count2); 
   int *result = new int[N]; 
   int index = 0; 
    for (int i = 0; i < count0; i++) { 
        result[index++] = remainder0[i]; 
        } 

    for (int i = 0; i < count1; i++) { 
        result[index++] = remainder1[i]; 
        } 

    for (int i = 0; i < count2; i++) { 
        result[index++] = remainder2[i]; 
        }

    int new_size = removeDuplicates(result, index);

    printf("%d\n", new_size);
    for (int i = 0; i < new_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    delete[] array;
    delete[] remainder0;
    delete[] remainder1;
    delete[] remainder2;
    delete[] result;

    return 0;
} 