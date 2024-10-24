#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    if (n > k*3 || n < k || k < 1 || k > 100 || n < 1 || n > 1000 )
    {
        cout << "Impossible";
        return 0;
    }

    vector<int> TeamSizes(k, 1);
    
    int leftover = n-k;

    for(int i = 0; i < k && leftover > 0; i++)
    {
        if(leftover == 1)
        {
            TeamSizes[i] += 1;
            leftover--;
        }
        else
        {
            TeamSizes[i] += 2;
            leftover -= 2;
        }
    }

    for(int x = 0; x < k; x++)
    {
        cout << TeamSizes[x] << " ";
    }

    return 0;
}