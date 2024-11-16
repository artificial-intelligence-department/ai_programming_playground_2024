#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N;

    int* a = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;
    int* b = new int[M];
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    int repetitive_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i] == b[j]) {
                repetitive_count++;
                break; 
            }
        }
    }

    int unique_count = N;
    for (int j = 0; j < M; j++) {
        bool is_unique = true;
        for (int i = 0; i < N; i++) {
            if (b[j] == a[i]) {
                is_unique = false; 
                break;
            }
        }
        if (is_unique) {
            unique_count++; 
        }
    }

    cout << repetitive_count << endl;
    cout << unique_count << endl;

    delete[] a;
    delete[] b;

    return 0;
}
