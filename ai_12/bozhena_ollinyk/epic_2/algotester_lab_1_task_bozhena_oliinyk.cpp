#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    long long H, M;

    cin >> H;
    cin >> M;

    bool win = true;

    for (int i = 0; i < 3; ++i)
    {
        long long h_i, m_i;
        cin >> h_i >> m_i;

        if (h_i != 0 && m_i != 0)
        {
            win = false;
            break;
        }

        H = H - h_i;
        M = M - m_i;
    }

    if (win && H > 0 && M > 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}