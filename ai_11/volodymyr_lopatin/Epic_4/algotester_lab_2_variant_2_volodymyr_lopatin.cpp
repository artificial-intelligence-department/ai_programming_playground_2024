#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    const int MAX = 100000;
    cin >> N;
    if (N < 1 || N > MAX) return 0;
    int *r = new int[N];
    for (int i = 0; i < N; i++) {
        int add;
        cin >> add;
        if (add < 0 || add > MAX) return 0;
        r[i] = add;
    }
    int a, b, c;
    cin >> a >> b >> c;
    if (a < 0 || a > MAX || b < 0 || b > MAX || c < 0 || c > MAX) return 0;

    vector<int> filtered;
    for (int i = 0; i < N; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            filtered.push_back(r[i]);
        }
    }
    int newSize = filtered.size();
    if (newSize < 2) {
        cout << '0';
        return 0;
    }
    int *narr = new int[newSize - 1];
    for (int i = 0; i < newSize-1; i++) {
        narr[i] = filtered[i] + filtered[i+1];
    }
    cout << newSize - 1 << endl;
    for (int i = 0; i < newSize - 1; i++) {
        cout << narr[i] << " ";
    }
    cout << endl;
    delete[] r;
    delete[] narr;
    return 0;
}