#include <iostream>
using namespace std;

int main(){
    int n, m;
    int res1;
    bool res2, res3;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    res1 = m + --n;
    cout << "1) m + --n: " << res1 << endl;

    res2 = m++ < ++n;
    cout << "2) m++ < ++n: " << res2 << endl;

    res3 = n-- < --m;
    cout << "3) n-- < --m: " << res3 << endl;

    return 0;
}