#include <iostream>
using namespace std;

int main(){
    int n, m, res1, res2, res3;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    res1 = n++*m;
    res2 = n++ < m;
    res3 = m-- > m; 
    cout << "n++*m = " << res1 << endl;
    cout << "n++ < m: " << res2 << endl;
    cout << "m-- > m: " << res3 << endl;

    return 0;
}