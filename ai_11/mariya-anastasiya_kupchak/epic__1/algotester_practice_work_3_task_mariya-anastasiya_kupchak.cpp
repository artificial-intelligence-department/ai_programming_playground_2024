// Найбільша зростаюча підпослідовність

#include <iostream>

using namespace std;

int main() 
{
    unsigned int n;
    cin >> n;

    if (n == 0) 
    {
        cout << 0 << endl;
        return 0;
    }

    long long *Mass = new long long[n];
    int *dp = new int[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> Mass[i];
        dp[i] = 1;
    }

    int maxLength = 1;

    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (Mass[j] < Mass[i] && dp[i] < dp[j] + 1) 
            {
                dp[i] = dp[j] + 1;
            }
        }
        maxLength = max(maxLength, dp[i]); 
    }

    cout << maxLength << endl;

    delete[] Mass;
    delete[] dp;

    return 0;
}
