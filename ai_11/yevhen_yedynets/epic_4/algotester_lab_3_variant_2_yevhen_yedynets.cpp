#include <iostream>
#include <vector>
 
using namespace std;

int main() {
    int N, M;

    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    cin >> M;
    vector<int> b(M);
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }
    
    bool in_a[101] = {false};
    bool in_b[101] = {false};

    for (int i = 0; i < N; ++i) {
        in_a[a[i]] = true;
    }

    for (int i = 0; i < M; ++i) {
        in_b[b[i]] = true;
    }

    int common_count = 0;
    int unique_count = 0;

    for (int i = 0; i <= 100; ++i) {
        if (in_a[i] && in_b[i]) {
            common_count++;
        }
        if (in_a[i] || in_b[i]) {
            unique_count++;
        }
    }

    cout << common_count << endl;
    cout << unique_count << endl;

    return 0;
}
