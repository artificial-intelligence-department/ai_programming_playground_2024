#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int a[N];
    bool unique[1000001] = { false };
    int unique_count = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (!unique[num]) {
            unique[num] = true;
            a[unique_count++] = num;
        }
    }

    for (int i = 0; i < unique_count - 1; i++) {
        for (int j = 0; j < unique_count - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << unique_count << endl;

    K = K % unique_count;

    for (int i = 0; i < unique_count; i++) {
        cout << a[(i + K) % unique_count] << " ";
    }
    cout << endl;

    return 0;
}



