#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Введіть значення m і n: ";
    cin >> m >> n;
   
    int result1 = n---m;
    bool result2 = m-- < n;

    cout << "result 1 (n---m): " << result1 << endl;
    cout << "result 2 (m--<n): " << (result2 ? "true" : "false") << endl;

    return 0;
}
