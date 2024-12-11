#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &r, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (r[j] > r[j + 1]) {
                int temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    bubbleSort(a, n);
    bubbleSort(b, m);
    int mina = a[0];
    int minb = b[0];
    int min = mina + minb;
    cout << min;
    return 0;
}
