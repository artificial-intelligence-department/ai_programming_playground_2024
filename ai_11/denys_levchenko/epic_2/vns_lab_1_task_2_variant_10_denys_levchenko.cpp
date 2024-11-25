#include <iostream>

using namespace std;
int main() {
    int n;
    int m;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter m" << endl;
    cin >> m;
    cout << n-- - m << endl;
    bool res1;
    res1 = m-- < n;
    cout << boolalpha << res1 << endl;
    bool res2;
    res2 = n++ > m;
    cout << boolalpha << res2 << endl;
    
    return 0;
}
