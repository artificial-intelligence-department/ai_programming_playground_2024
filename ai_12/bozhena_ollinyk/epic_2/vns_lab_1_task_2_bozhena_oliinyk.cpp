#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, m;

    cout << "Введіть n" << endl;
    cin >> n;
    cout << "Введіть m" << endl;
    cin >> m;

    int pluses = n++ + m;
    cout << pluses;

    int minusn = m-- > n;
    cout << minusn << endl;

    int minusm = n-- > m;
    cout << minusm << endl;

    return 0;
} 