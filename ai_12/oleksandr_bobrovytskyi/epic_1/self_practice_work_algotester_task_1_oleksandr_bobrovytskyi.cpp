#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    if (1 > n || n > 1000)
    {
        cout << "invalid value" << endl;
        return 1;
    }
    
    
    vector<int> votes(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> votes[i];
        if (1 > votes[i] || votes[i] > 1000000)
        {
            cout << "invalid value" << endl;
            return 1;
        }
    }
    
    int GreatestCommonDevider = votes[0];

    for (int i = 1; i < n; ++i)
    {
        GreatestCommonDevider = gcd(GreatestCommonDevider, votes[i]);
    }

    int TotalSeats = 0;
    for (int i = 0; i < n; ++i)
    {
        TotalSeats += votes[i] / GreatestCommonDevider;
    }

     cout << TotalSeats << endl;

    return 0;
}