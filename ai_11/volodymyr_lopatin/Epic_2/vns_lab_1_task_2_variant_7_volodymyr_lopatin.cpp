#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << "m+--n is: " << (m+--n) << endl;
    cout << "m++<++n is: " << (m++<++n) << endl;
    cout << "n--<--m is: " << (n--<--m) << endl;

    return 0;
}