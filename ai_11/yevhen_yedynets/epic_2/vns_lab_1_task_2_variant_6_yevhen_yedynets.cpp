#include<iostream>

using namespace std;

int main(){
    int m, n, x;
    bool y, z;

    cin >> m;
    cin >> n;

    x = m - ++n;
    y = ++m > --n;
    z = --n < ++m;

    cout << "1) " << x << endl;
    cout << "2) " << boolalpha << y << endl;
    cout << "3) " << boolalpha << z << endl;


    return 0;
}