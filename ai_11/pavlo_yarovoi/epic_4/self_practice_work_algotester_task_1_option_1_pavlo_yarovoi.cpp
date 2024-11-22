#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;

    int r[N];  
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    unordered_set<int> to_remove = {a, b, c};
    int filtered[N]; 
    int filtered_size = 0;

    for (int i = 0; i < N; ++i) {
        if (to_remove.find(r[i]) == to_remove.end()) {
            filtered[filtered_size++] = r[i];  
        }
    }

    int M = filtered_size - 1;
    if (M <= 0) {
        cout << 0 << endl;
        return 0;
    }

    int sums[M];
    for (int i = 0; i < M; ++i) {
        sums[i] = filtered[i] + filtered[i + 1];  
    }

    cout << M << endl;
    for (int i = 0; i < M; ++i) {
        cout << sums[i] << " ";
    }
    cout << endl;

    return 0;
}

