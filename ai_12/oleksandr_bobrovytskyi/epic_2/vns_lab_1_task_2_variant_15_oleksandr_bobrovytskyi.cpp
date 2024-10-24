#include <iostream>

using namespace std;

int main()
{
    double n,m = 0;

    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    cout << "1) n++ - m = " << n++ - m << endl;

    cout << "2) m-- > n  -  " << ((m-- > n)? "True" : "False") << endl;

    cout << "3) n-- > m  -  " << ((n-- > m)? "True" : "False") << endl;

    return 0;
}