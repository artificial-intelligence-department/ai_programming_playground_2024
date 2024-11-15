
#include <iostream>
using namespace std;

int main() {
    int n;
    int m;

    cout << "Enter value of n: " << endl;
    cin >> n;
    cout << "Enter value of m: " << endl;
    cin >> m;

    // 1) n---m
    int result1 = n---m;
    cout << "n---m:   " << result1 << ", n = " << n << ", m = " << m << endl;

    // 2) m--<n
    bool result2 = m--<n;
    cout << "m--<n: " << result2 << ", n = " << n << ", m = " << m << endl;

    // 3) n++>m
    bool result3 = n++>m;
    cout << "n++>m:   " << result3 << ", n = " << n << ", m = " << m << endl;

    return 0;
}