#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int *array = new int[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int* zero = partition(array, array + N, [](int i) { return i % 3 == 0; });
    int* one = partition(zero, array + N, [](int i) { return i % 3 == 1; });

    sort(array, zero);
     sort(zero, one, [](int a, int b) {
        return a > b;});
    sort(one, array + N);

    int *end = unique(array, array + N); 
    int new_size = distance(array, end);

    printf("%d\n", new_size);
    for (int i = 0; i < new_size; i++) {
        printf("%d ", array[i]); 
    }

    delete[] array;

    return 0;
}