#include <iostream>
#include <vector>
#include <cmath> // для abs
#include <algorithm> // для sort

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n); // ініцйіалізація векторів
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    long long sum = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end()); // сортування векторів
    sort(c.begin(), c.end());

    int A = a[n / 2];
    int B = b[n / 2]; // обраховування медіани
    int C = c[n / 2];

    for (int i = 0; i < n; i++)
    {
        long long min = abs(A - a[i]) + abs(B - b[i]) + abs(C - c[i]);
        sum += min;  // обчислення суми
    }
    
    
    cout << sum << endl;
    return 0;
}