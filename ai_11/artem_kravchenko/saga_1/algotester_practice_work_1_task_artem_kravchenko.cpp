#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    long long sum = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int A = a[n / 2];
    int B = b[n / 2];
    int C = c[n / 2];

    for (int i = 0; i < n; i++)
    {
        long long min = abs(A - a[i]) + abs(B - b[i]) + abs(C - c[i]);
        sum += min;
    }
    
    
    cout << sum << endl;
    return 0;
}