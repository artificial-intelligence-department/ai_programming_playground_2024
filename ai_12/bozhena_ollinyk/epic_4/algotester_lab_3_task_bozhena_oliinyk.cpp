#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N;

    int n[N];
    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }

    cin >> M;
    int m[M];
    for (int i = 0; i < M; i++)
    {
        cin >> m[i];
    }

    int combined[N + M];
    for (int i = 0; i < N; i++)
    {
        combined[i] = n[i];
    }
    for (int i = 0; i < M; i++)
    {
        combined[N + i] = m[i];
    }

    sort(combined, combined + N + M);

    int uniqueCount = 0;
    for (int i = 0; i < N + M; i++)
    {
        if (i == 0 || combined[i] != combined[i - 1])
        {
            uniqueCount++;
        }
    }

    int commonCount = 0;
    int i = 0, j = 0;
    sort(n, n + N); 
    sort(m, m + M);
    while (i < N && j < M)
    {
        if (n[i] == m[j])
        {
            commonCount++;
            int value = n[i];
            while (i < N && n[i] == value) i++;
            while (j < M && m[j] == value) j++;
        }
        else if (n[i] < m[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << commonCount << endl;
    cout << uniqueCount << endl;

    return 0;
}
