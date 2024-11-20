#include <iostream>
#include <algorithm>

using namespace std;

bool customComparator(int a, int b) {
    //остача парна сортуємо по зростанню
    if (a % 3 == 0 || a % 3 == 2) {
        return a < b;
    } else {
        return a > b; //по спаданню
    }
}

int main() {
    int N;
    cin >> N;

    int numbers[1000];
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int* div_by_3_0 = partition(numbers, numbers + N, [](int x) { return x % 3 == 0; });
    int* div_by_3_1 = partition(div_by_3_0, numbers + N, [](int x) { return x % 3 == 1; });


    sort(numbers, div_by_3_0, customComparator);
    sort(div_by_3_0, div_by_3_1, customComparator);
    sort(div_by_3_1, numbers + N, customComparator);

    int* unique_arr = unique(numbers, numbers + N);

    int M = unique_arr - numbers;
    cout << M << endl;

    for (int i = 0; i < M; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
