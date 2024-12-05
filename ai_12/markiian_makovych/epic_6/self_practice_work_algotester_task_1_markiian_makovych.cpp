#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int t, z, y;
    int left = 0, right = 2000 * 2000;
    int result = right;

    int boys[2000][3];

    for (int i = 0; i < n; i++)
    {
        cin >> boys[i][0] >> boys[i][1] >> boys[i][2];
    }

     while (left <= right)
    {
        int mid = (left + right) / 2;
        int totalBalloons = 0;

        for (int i = 0; i < n; i++)
        {
            t = boys[i][0];
            z = boys[i][1];
            y = boys[i][2];

            int cycles = mid / (z * t + y);

            int remainingTime = mid % (z * t + y);

            int balloonsInCycles = cycles * z;
            int additionalBalloons = min(remainingTime / t, z);

            totalBalloons += balloonsInCycles + additionalBalloons;

            if (totalBalloons >= m)
            {
                break;
            }
        }

        if (totalBalloons >= m)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
