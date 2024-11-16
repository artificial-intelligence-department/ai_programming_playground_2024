#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int* a = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int M;
    cin >> M;
    int* b = new int[M];

    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    int cnt1 = 0;
    int cnt2 = N + M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i] == b[j]) {
                cnt1++;
                cnt2--;
                break;
            }
        }
    }

    cout << cnt1 << endl;
    cout << cnt2;

    delete[] a;
    delete[] b;

    return 0;
}