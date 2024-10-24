#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long mDiametr = min({a, b, c});

    cout << mDiametr << "\n";

    return 0;
}