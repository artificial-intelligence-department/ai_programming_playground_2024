#include <iostream>
using namespace std;
int main(){
    int m,n;
    cout << endl;
    cin >> m >> n;
    cout << m + --n << endl;
    cout << (m++ < ++n) << endl;
    cout << (n-- < --m) << endl;
    return 0;
}