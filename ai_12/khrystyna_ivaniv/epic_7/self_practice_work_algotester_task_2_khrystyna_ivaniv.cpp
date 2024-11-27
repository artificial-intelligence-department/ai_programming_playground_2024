#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;

}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = a[0];

    for (int i = 1; i < n; i++)
    {
        result = gcd(result, a[i]);
    }

    long long amount = 0;
    for (int i = 0; i < n; i++)
    {
        if(result != 0)
        amount += a[i] / result;
    }
    cout << amount;

    return 0;
}
