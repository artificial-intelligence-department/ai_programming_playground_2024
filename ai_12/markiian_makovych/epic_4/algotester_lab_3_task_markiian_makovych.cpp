#include <iostream>

using namespace std;

int main()
{
    int N, M, count1 = 0;
    cin >> N;
    int firstArr[N] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> firstArr[i];
    }
    cin >> M;
    int secondArr[M] = {};
    for (int i = 0; i < M; i++)
    {
        cin >> secondArr[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (firstArr[i] == secondArr[j])
            {
                count1++;
            }
        }
    }

    cout << count1 << endl;
    cout << (N + M) - count1 << endl;

    return 0;
}