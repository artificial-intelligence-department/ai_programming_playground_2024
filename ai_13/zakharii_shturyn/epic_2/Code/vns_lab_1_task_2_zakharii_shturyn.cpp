// 18 варіант
#include <iostream>
using namespace std;

int main() { 

    double n;
    double m;
    cin >> n;
    cin >> m;
    cout << n++ * m << endl;
    bool a = n++ < m;
    bool b = m-- > m;
    cout << a << endl;
    cout << b << endl;


    return 0;
}