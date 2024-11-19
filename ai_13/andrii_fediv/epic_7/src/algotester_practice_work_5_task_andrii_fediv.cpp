#include <iostream>

using namespace std;

int main()
{
    long long h, m;
    cin >> h >> m;
    bool triger = true;
    for (int i = 0; i < 3; i++)
    {
        long long hm, mm;
        cin >> hm >> mm;
        if (hm > 0 && mm > 0)
        {
            triger = false;
            break;
        }
        h -= hm;
        m -= mm;
    }

    if (h > 0 && m > 0 && triger)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}