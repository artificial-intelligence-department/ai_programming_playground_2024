#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int intersection = 0, symmetricDifference = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                ++intersection;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bool notFound = true;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                notFound = false;
                b[j] = -1;
            }
        }

        if (notFound) {
            ++symmetricDifference;
        }
    }

    for (int i = 0; i < m; i++) {
        bool notFound = true;
        for (int j = 0; j < n; j++) {
            if (b[i] == a[j]) {
                notFound = false;
            }
        }

        if (notFound) {
            ++symmetricDifference;
        }
    }

    cout << intersection << endl << symmetricDifference;

    return 0;
}