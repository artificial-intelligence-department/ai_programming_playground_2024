#include <iostream>
#include <climits>

using namespace std;

const int MAX_N = 1500;

int n, m, k;
int f[MAX_N][MAX_N];
int InRowMax[MAX_N][MAX_N];

void MaxRow() 
{
    for (int i = 0; i < n; i++) 
    {
        int queue[MAX_N], head = 0, tail = 0;
        for (int j = 0; j < m; j++) 
        {
            if (head < tail && queue[head] <= j - k) 
            {
                head++;
            }

            while (head < tail && f[i][queue[tail - 1]] <= f[i][j]) 
            {
                tail--;
            }

            queue[tail++] = j;

            if (j >= k - 1) 
            {
                InRowMax[i][j - k + 1] = f[i][queue[head]];
            }
        }
    }
}

int minMax() 
{
    int result = INT_MAX;

    for (int j = 0; j <= m - k; j++) 
    {
        int queue[MAX_N], head = 0, tail = 0;

        for (int i = 0; i < n; i++) 
        {
            if (head < tail && queue[head] <= i - k) 
            {
                head++;
            }

            while (head < tail && InRowMax[queue[tail - 1]][j] <= InRowMax[i][j]) 
            {
                tail--;
            }

            queue[tail++] = i;

            if (i >= k - 1) {
                result = min(result, InRowMax[queue[head]][j]);
            }
        }
    }

    return result;
}

int main() 
{
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> f[i][j];
        }
    }

    MaxRow();

    int result = minMax();

    cout << result << "\n";

    return 0;
}
