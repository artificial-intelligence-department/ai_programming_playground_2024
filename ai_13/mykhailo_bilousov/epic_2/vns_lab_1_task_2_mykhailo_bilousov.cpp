#include <iostream>
using namespace std;

int main() {
    int n,m;
    cout << "Enter n, m" << endl;
    cin >> n >> m;
    cout << "++n*++m " << ++n*++m << endl;
    cout << "m++<n " << (m++<n) << endl;
    cout << "n++>m " << (n++>m) << endl;
}