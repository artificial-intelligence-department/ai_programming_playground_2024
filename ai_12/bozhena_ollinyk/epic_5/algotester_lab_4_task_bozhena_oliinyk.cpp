#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int n[N];
    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }

    int zero[N], one[N], two[N];
    int z = 0, o = 0, t = 0;

    for (int i = 0; i < N; i++)
    {
        if (n[i] % 3 == 0)
        {
            zero[z++] = n[i];
        }
        else if (n[i] % 3 == 1)
        {
            one[o++] = n[i];
        }
        else
        {
            two[t++] = n[i];
        }
    }

    sort(zero, zero + z);
    sort(one, one + o, greater<int>());
    sort(two, two + t);

    int result[N], count = 0;

    for (int i = 0; i < z; i++)
    {
        result[count++] = zero[i];
    }
    for (int i = 0; i < o; i++)
    {
        result[count++] = one[i];
    }
    for (int i = 0; i < t; i++)
    {
        result[count++] = two[i];
    }

    count = unique(result, result + count) - result;

    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
