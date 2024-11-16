#include <iostream>
using namespace std;

int main()
{
    long long h[4], m[4], h1, m1;
    bool win = true;

    for (int i = 0; i < 4; i++)
    {
        cin >> h[i] >> m[i];
        
        if (i == 0)
        {
            h1 = h[i];
            m1 = m[i];
        }
        
        else
        {
            if ((h[i] != 0) && (m[i] != 0))
            {
                win = false;
            }
            h1 -= h[i];
            m1 -= m[i];
        }
    }

    if ((h1 <= 0) || (m1 <= 0))
    {
        win = false;
    }

    if (win) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}