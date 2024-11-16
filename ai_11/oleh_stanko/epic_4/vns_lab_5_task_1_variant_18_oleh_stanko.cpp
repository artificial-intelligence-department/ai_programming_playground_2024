#include <iostream>
using namespace std;

void finding_max_element(int** a, int n, int N);
bool check(int** a, int N);

int main() 
{ 
    int N;
    cin >> N;
    int** a = new int*[N];
    for (int i = 0; i < N; i++) 
    {
        a[i] = new int[N];
        for (int j = 0; j < N; j++) 
        {   
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) 
    {
        finding_max_element(a, i, N);
    }
    
    bool answer = check(a, N);
    if (answer)
    {
        cout << "\nYes"; 
    }
    else 
    {
        cout << "\nNo";
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {   
            cout << a[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) 
    {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}

void finding_max_element(int** a, int n, int N) 
{    
    int m_i = n;
    int m_j = N - 1 - n;
    int m_e = a[m_i][m_j];
    
    for (int i = n; i < N; i++) 
    { 
        for (int j = N - 1 - n; j < N; j++) 
        {
            if (a[i][j] > m_e) 
            {
                m_e = a[i][j]; 
                m_i = i; 
                m_j = j; 
            }
        }
    }

    for (int j = 0; j < N; j++) 
    {
        int temp = a[n][j];
        a[n][j] = a[m_j][j];
        a[m_j][j] = temp;
    }

    for (int i = 0; i < N; i++) 
    {
        int temp = a[i][N - 1 - n];
        a[i][N - 1 - n] = a[i][m_i];
        a[i][m_i] = temp;
    }
}

bool check(int** a, int N)
{
    for (int i = 1; i < N; i++)
    {
        if (a[i-1][N-i] <= a[i][N-i-1])
        {
            return false;
        }
    }
    return true;
}
