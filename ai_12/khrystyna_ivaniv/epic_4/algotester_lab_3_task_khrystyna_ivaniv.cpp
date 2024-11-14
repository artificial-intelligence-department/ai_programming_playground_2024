#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> array1(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array1[i];
    }
    int M;
    cin >> M;
    vector<int> array2(M);
    for (int i = 0; i < M; i++)
    {
        cin >> array2[i];
    }
    int common = 0;
    int unique = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (array1[i] == array2[j])
            {
                common++;
                break;
            }
        }
    }
    unique = N + M - common;
    cout << common << endl;
    cout << unique;
    return 0;
}