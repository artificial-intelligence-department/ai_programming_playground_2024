#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, count = 0;

    cin >> N;
    if(N > 100 || N < 0)
    {
        return 0;
    }

    vector<int> v1(N);

    for(int i = 0; i < N; i++)
    {
        cin >> v1[i];
        if(v1[i] > 100 || v1[i] < 0)
        {
            return 0;
        }
    }
    
    cin >> M;
    if(M > 100 || M < 0)
    {
        return 0;
    }

    vector<int> v2(M);  

    for(int i = 0; i < M; i++)
    {
        cin >> v2[i];
        if(v2[i] > 100 || v2[i] < 0)
        {
            return 0;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(v1[i] == v2[j])
            {
                count++;
            }
        }
    }

    cout << count << endl;
    cout << (N + M) - count;

    return 0;
}