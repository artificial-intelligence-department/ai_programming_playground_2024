#include <iostream>
using namespace std;

int main() {
    unsigned int n, k=1;
    cin >> n;
    unsigned int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int f[n];
    f[0]=1;
    for (int i=1; i<n; i++) {
            f[i]=1;
            for (int j=0; j<=i-1; j++) {
                if (a[j] < a[i]) {
                    f[i] = max (f[i], f[j]+1);
                }
            }
    }
    for (int i : f) {
        if (i>k) {
            k=i;
        }
    }
    cout << k;
    return 0;}


