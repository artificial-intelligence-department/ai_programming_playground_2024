#include <iostream>
using namespace std;

int main()
{
    double n, m;

    cout << "n: ";
    cin >> n;
    cout << "m: ";
    cin >> m;

    cout << "\n Results: \n";

    cout << "- -m - ++n: " << (-(-m) - (++n)) << endl;
    cout << "m * n < n++: " << ((m * n < n++) ? "true" : "false") << endl;
    cout << "n-- > m++: " << ((n-- > m++) ? "true" : "false") << endl;

    return 0;
}
