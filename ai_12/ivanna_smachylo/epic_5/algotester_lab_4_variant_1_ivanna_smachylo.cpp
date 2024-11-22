#include <iostream>
#include <algorithm>

using namespace std;

void results(const int *result, int size) 
{
    cout << size << "\n";
    for (int i = 0; i < size; i++) 
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}

void difference(const int *n, int N, const int *m, int M) 
{
    int result[1000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) 
    {
        if (n[i] < m[j]) 
        {
            result[resultSize++] = n[i++];
        } 
        else if (n[i] > m[j]) 
        {
            j++;
        } 
        else 
        {
            i++;
            j++;
        }
    }

    while (i < N) 
    {
        result[resultSize++] = n[i++];
    }

    results(result, resultSize);
}

void section(const int *n, int N, const int *m, int M) 
{
    int result[1000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) 
    {
        if (n[i] < m[j]) 
        {
            i++;
        } 
        else if (n[i] > m[j]) 
        {
            j++;
        } 
        else 
        {
            result[resultSize++] = n[i];
            i++;
            j++;
        }
    }

    results(result, resultSize);
}

void unionNM(const int *n, int N, const int *m, int M) 
{
    int result[2000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) 
    {
        if (n[i] < m[j]) 
        {
            result[resultSize++] = n[i++];
        } 
        else if (n[i] > m[j]) 
        {
            result[resultSize++] = m[j++];
        } 
        else 
        {
            result[resultSize++] = n[i];
            i++;
            j++;
        }
    }

    while (i < N) 
    {
        result[resultSize++] = n[i++];
    }

    while (j < M) 
    {
        result[resultSize++] = m[j++];
    }

    results(result, resultSize);
}

void Difference(const int *n, int N, const int *m, int M) 
{
    int result[2000], resultSize = 0;

    int i = 0, j = 0;
    while (i < N && j < M) 
    {
        if (n[i] < m[j]) 
        {
            result[resultSize++] = n[i++];
        } 
        else if (n[i] > m[j]) 
        {
            result[resultSize++] = m[j++];
        } 
        else 
        {
            i++;
            j++;
        }
    }

    while (i < N) 
    {
        result[resultSize++] = n[i++];
    }

    while (j < M) 
    {
        result[resultSize++] = m[j++];
    }

    results(result, resultSize);
}

int main() {
    int N, M;

    cin >> N;
    int n[1000];
    for (int i = 0; i < N; i++) 
    {
        cin >> n[i];
    }

    cin >> M;
    int m[1000];
    for (int i = 0; i < M; i++) 
    {
        cin >> m[i];
    }

    sort(n, n + N);
    sort(m, m + M);

    difference(n, N, m, M);
    cout << "\n";

    difference(m, M, n, N);
    cout << "\n";

    section(n, N, m, M);
    cout << "\n";

    unionNM(n, N, m, M);
    cout << "\n";

    Difference(n, N, m, M);
    cout << "\n";

    return 0;
}