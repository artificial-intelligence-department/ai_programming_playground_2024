#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    vector<int> sum(n - 1);
    cout << "Input height-->";
    cin >> n;
    cout << "Input width-->";
    cin >> m;
    while (n--)
    {
        int n2 = n <= m ? n : m;
        for (size_t i2 = 0; i2 < m; i2++)
        {
            int el;
            cin >> el;
            if (n >= 1 && i2 < m - 1 && i2 < n2)
                sum[i2] += el;
        }
        n2--;
    }
    unsigned int max_int = -1;
    int acc = 1 - (max_int / 2);
    for (int s : sum)
        if (s > acc)
            acc = s;
    cout << "the highest sum is: " << acc;
    return 0;
}